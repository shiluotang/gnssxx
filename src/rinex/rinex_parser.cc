#include "rinex/rinex_parser.hh"

namespace gnssxx {
namespace rinex {

rinex_parser::rinex_parser()
    :_M_parsing_header(true)
{
}

rinex_parser::~rinex_parser() {
}

bool rinex_parser::parse_version_type(
        std::istream &s,
        rinex_file_version &ver,
        std::string &type) {
    return true;
}

bool rinex_parser::parse(std::istream &in, rinex_file &file) {
    return false;
}

} // namespace rinex
} // namespace gnssxx
