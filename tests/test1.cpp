#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctime>

#include "../src/gnssxx.hpp"

namespace gnssxx {
    template <
                typename CharT,
                typename Traits = std::char_traits<CharT>,
                typename Alloc = std::allocator<CharT>
                    >
    class basic_simplebuf : public std::basic_streambuf<CharT> {
    public:
        typedef typename Traits::int_type int_type;

    public:
        virtual int_type underflow() { return 0; }

        virtual int_type overflow(int_type ch = Traits::eof()) { return 0; }

        virtual int_type sync() { return 0; }
    };

    typedef basic_simplebuf<char> simplebuf;
    typedef basic_simplebuf<wchar_t> wsimplebuf;

    class epoch_time {};

    class unix_time {};

    class gps_time {};

    class tai_time {};

    class utc_time {};

    namespace time {
        time_t gps() { return 0; }
        time_t utc() { return 0; }
        time_t tai() { return 0; }
        time_t tai(std::time_t const &t) { return t; }

        time_t unix() {
            std::time_t t = 0;
            if (std::time(&t) == static_cast<std::time_t>(-1))
                throw std::runtime_error("Can't get time from c library!");
            return t;
        }
    }
}

int main(int argc, char *argv[]) {
    using namespace std;
    using namespace gnssxx;

    cout << static_cast<time_t>(unixtime::now()) << endl;
    cout << time::utc() << endl;
    cout << time::tai(3) << endl;
    return EXIT_SUCCESS;
}
