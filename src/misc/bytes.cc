#include <iomanip>
#include <ostream>
#include <algorithm>

#include "misc/utils.hpp"
#include "misc/bytes.hpp"

namespace gnssxx {
namespace misc {

bytes::bytes(void const *addr, size_t n) :_M_data() {
    _M_data.resize(n);
    std::copy_n(static_cast<uint8_t const*>(addr), n, &_M_data[0]);
}

void bytes::print(std::ostream& out) const {
    uint8_t const *p = static_cast<uint8_t const*>(&_M_data[0]);
    gnssxx::misc::ios_guarder guarder(out);
    for (int i = 0, n = _M_data.size(); i < n; ++i) {
        out
            << std::setw(2)
            << std::setfill('0')
            << std::hex
            << std::uppercase
            << (p[i] & 0xff);
    }
}

std::ostream& operator<<(std::ostream &out, bytes const &b) {
    b.print(out);
    return out;
}

} // namespace misc
} // namespace gnssxx
