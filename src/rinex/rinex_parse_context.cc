#include "rinex/rinex_parse_context.hh"

namespace gnssxx {
namespace rinex {

rinex_parse_context::~rinex_parse_context() {
}

rinex_metadata const&
rinex_parse_context::get_metadata() const {
    return _M_metadata;
}

rinex_metadata&
rinex_parse_context::get_metadata(){
    return _M_metadata;
}

rinex_file_header const&
rinex_parse_context::get_header() const {
    return _M_header;
}

rinex_file_header&
rinex_parse_context::get_header() {
    return _M_header;
}

void
rinex_parse_context::set_metadata(rinex_metadata const &value) {
    _M_metadata = value;
}

void
rinex_parse_context::set_header(rinex_file_header const &value) {
    _M_header = value;
}

} // namespace rinex
} // namespace gnssxx
