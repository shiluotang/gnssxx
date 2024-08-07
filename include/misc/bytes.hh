#ifndef GNSSXX_MISC_BYTES_HH_INCLUDED
#define GNSSXX_MISC_BYTES_HH_INCLUDED

#include <cstddef>
#include <cstdint>
#include <vector>
#include <iosfwd>

namespace gnssxx {
namespace misc {

class bytes {
    public:
        typedef uint8_t ubyte;
        typedef std::vector<ubyte> value_type;

        bytes(bytes const&);
        ~bytes();

        bytes(void const *addr, size_t n);
        bytes(char const*);
        bytes();

        void print(std::ostream& out) const;

        bytes& operator=(bytes const&);
        bytes& operator=(char const*);
        bytes& operator+=(bytes const&);
        bytes operator+(bytes const&) const;

        bool operator<(bytes const&) const;
        bool operator==(bytes const&) const;

        ubyte& operator[](size_t);
        ubyte const& operator[](size_t) const;
        void swap(bytes&);
        size_t size() const;
        void const* addr() const;
        void* addr();
    protected:
        bytes& assign(bytes const&);
        bytes& assign(void const*, size_t);
        bytes& append(bytes const&);
        bytes& append(void const*, size_t);
        int compare(bytes const&) const;
    private:
        value_type _M_data;
};

std::ostream& operator<<(std::ostream&, bytes const&);

} // namespace misc
} // namespace gnssxx

#endif // GNSSXX_MISC_BYTES_HH_INCLUDED
