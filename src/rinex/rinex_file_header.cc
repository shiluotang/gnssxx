#include <string>

#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_file_header.hh"

namespace gnssxx {
namespace rinex {

rinex_file_version const& rinex_file_header::version() const {
    return _M_version;
}

std::string rinex_file_header::get_pgm() const {
    return _M_pgm;
}

std::string rinex_file_header::get_run_by() const {
    return _M_run_by;
}

std::string rinex_file_header::get_date() const {
    return _M_date;
}

bool rinex_file_header::has_ion() const {
    return !!_M_ion;
}

ion const& rinex_file_header::get_ion() const {
    return *_M_ion;
}

bool rinex_file_header::has_leap_seconds() const {
    return !!_M_leap_seconds;
}

int rinex_file_header::get_leap_seconds() const {
    return *_M_leap_seconds;
}

} // namespace rinex
} // namespace gnssxx
