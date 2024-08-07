#include "rinex/rinex_metadata.hh"

namespace gnssxx {
namespace rinex {

rinex_file_version
rinex_metadata::get_version() const {
    return _M_version;
}

rinex_file_type
rinex_metadata::get_type() const {
    return _M_type;
}

rinex_file_satsys
rinex_metadata::get_satsys() const {
    return _M_satsys;
}

void
rinex_metadata::set_version(rinex_file_version const &value) {
    _M_version = value;
}

void
rinex_metadata::set_type(rinex_file_type const &value) {
    _M_type = value;
}

void
rinex_metadata::set_satsys(rinex_file_satsys const &value) {
    _M_satsys = value;
}

} // namespace rinex
} // namespace gnssxx
