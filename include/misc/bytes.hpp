#ifndef GNSSXX_MISC_BYTES_HPP_INCLUDED
#define GNSSXX_MISC_BYTES_HPP_INCLUDED

#include <cstddef>
#include <cstdint>
#include <vector>
#include <iosfwd>

namespace gnssxx {
namespace misc {

class bytes {
    public:
        bytes(void const *addr, size_t n);

        void print(std::ostream& out) const;
    protected:
    private:
        std::vector<uint8_t> _M_data;
};

std::ostream& operator<<(std::ostream&, bytes const&);

} // namespace misc
} // namespace gnssxx

#endif // GNSSXX_MISC_BYTES_HPP_INCLUDED
