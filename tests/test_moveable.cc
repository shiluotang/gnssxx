#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

// #include <gtest/gtest.h>

// namespace {

class frame_printer {
    public:
        frame_printer(std::string const &name)
            : _M_name(name)
            , _M_call_depth(call_depth_after_enter())
        {
            std::cout << indent() << "[call-frame] >>> " << _M_name << std::endl;
        }

        ~frame_printer() {
            std::cout << indent() << "[call-frame] <<< " << _M_name << std::endl;
            call_depth_before_leave();
        }

#if __cplusplus >= 201103L
        // TODO FIXME find out early destruction reason!!!
        static
        std::shared_ptr<frame_printer> instance(std::string const &name) {
            std::shared_ptr<frame_printer> p(new frame_printer(name));
            return p;
        }
#endif

        std::string indent() const {
            return std::string(_M_call_depth - 1, '*');
        }
    protected:

        static
        int call_depth_after_enter() {
            return ++_S_calls;
        }

        static
        int call_depth_before_leave() {
            return _S_calls--;
        }
    private:
        std::string _M_name;
        int _M_call_depth;
        static int _S_calls;
};

int frame_printer::_S_calls = 0;

#ifndef FRAME_RECORD
#    define FRAME_RECORD() \
    frame_printer __frame_printer(__PRETTY_FUNCTION__)
#endif

#ifndef FRAME_INDENT
#    define FRAME_INDENT() __frame_printer.indent()
#endif

class moveable_data {
    public:
        moveable_data(std::string const &data)
            : _M_data(data)
            , _M_name(next_ctor_ctor_name())
        {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
        }

        moveable_data(moveable_data const &other)
            : _M_data(other._M_data)
            , _M_name(next_copy_ctor_name())
        {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
            std::cout << FRAME_INDENT() << ", other = " << other << std::endl;
        }

#if __cplusplus >= 201103L
        moveable_data(moveable_data &&other) noexcept
            : _M_data(std::move(other._M_data))
            , _M_name(next_move_ctor_name())
        {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
            std::cout << FRAME_INDENT() << ", other = " << other << std::endl;
        }
#endif

        virtual
        ~moveable_data() {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
        }

        moveable_data& operator=(moveable_data const &other) {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
            std::cout << FRAME_INDENT() << ", other = " << other << std::endl;
            if (this == &other)
                return *this;
            _M_data = other._M_data;
            return *this;
        }

#if __cplusplus >= 201103L
        moveable_data& operator=(moveable_data &&other) {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
            std::cout << FRAME_INDENT() << ", other = " << other << std::endl;
            if (this == &other)
                return *this;
            _M_data = std::move(other._M_data);
            return *this;
        }
#endif

        moveable_data& operator+=(moveable_data const &other) {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
            std::cout << FRAME_INDENT() << ", other = " << other << std::endl;
            _M_data += other._M_data;
            return *this;
        }

        moveable_data operator+(moveable_data const &other) const {
            FRAME_RECORD();
            std::cout << FRAME_INDENT() << ", *this = " << *this << std::endl;
            std::cout << FRAME_INDENT() << ", other = " << other << std::endl;
            moveable_data copy(*this);
            copy.operator+=(other);
            return copy; // copy elision
            // return std::move(copy); // no copy elision
            // return moveable_data(*this)+=other;
        }

        void print(std::ostream &out) const {
            out << "moveable_data@" << static_cast<void const*>(this)
                << "{_M_data = \"" << _M_data << "\""
                << ", _M_name = \"" << _M_name << "\""
                << "}";
        }
    protected:
        static
        std::string next_ctor_ctor_name() {
            std::ostringstream oss;
            oss << "ctor-ctor #" << ++_S_ctor_ctor_counter;
            return oss.str();
        }

        static
        std::string next_copy_ctor_name() {
            std::ostringstream oss;
            oss << "copy-ctor #" << ++_S_copy_ctor_counter;
            return oss.str();
        }

        static
        std::string next_move_ctor_name() {
            std::ostringstream oss;
            oss << "move-ctor #" << ++_S_move_ctor_counter;
            return oss.str();
        }

    private:
        std::string _M_data;
        std::string _M_name;
        static int _S_ctor_ctor_counter;
        static int _S_copy_ctor_counter;
        static int _S_move_ctor_counter;
        friend
        std::ostream& operator<<(std::ostream &os, moveable_data const& d);
};

int moveable_data::_S_ctor_ctor_counter = 0;
int moveable_data::_S_copy_ctor_counter = 0;
int moveable_data::_S_move_ctor_counter = 0;

extern
std::ostream& operator<<(std::ostream &os, moveable_data const& d) {
    d.print(os);
    return os;
}

// } // namespace anonymous


int main(int argc, char* argv[]) {
    moveable_data a("hello ");
    moveable_data b("world!");
    moveable_data r = a + b;
    moveable_data c = r;
    std::cout << "r = " << r << std::endl;
    std::cout << "c = " << c << std::endl;
    return EXIT_SUCCESS;
}
