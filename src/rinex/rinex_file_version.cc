#include <iomanip>
#include <ostream>
#include "rinex/rinex_file_version.hh"

namespace gnssxx {
namespace rinex {

rinex_file_version::rinex_file_version(int major, int minor)
    : _M_major(major)
    , _M_minor(minor)
{
}

rinex_file_version::rinex_file_version()
    : _M_major(0)
    , _M_minor(0)
{
}

int rinex_file_version::get_major() const {
    return _M_major;
}

int rinex_file_version::get_minor() const {
    return _M_minor;
}

void rinex_file_version::set_major(int value) {
    _M_major = value;
}

void rinex_file_version::set_minor(int value) {
    _M_minor = value;
}

void rinex_file_version::print(std::ostream& out) const {
    out
        << _M_major
        << "."
        << std::setw(2) << std::setfill('0') << _M_minor;
}

bool rinex_file_version::operator<(rinex_file_version const &other) const {
    return _M_major < other._M_major
        || (_M_major == other._M_major && _M_minor < other._M_minor);
}

bool rinex_file_version::operator==(rinex_file_version const &other) const {
    return _M_major == other._M_major
        && _M_minor == other._M_minor;
}

std::ostream& operator<<(std::ostream &os, rinex_file_version const &v) {
    v.print(os);
    return os;
}

} // namespace rinex
} // namespace gnssxx
