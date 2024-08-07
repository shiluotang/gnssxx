#include <string>
#include <istream>
#include <iomanip>
#include <vector>

#include "rinex/rinex_file_header.hh"
#include "rinex/rinex_file_satsys.hh"
#include "rinex/rinex_file_type.hh"
#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_parse_context.hh"
#include "rinex/rinex_header_parser_factory.hh"
#include "rinex/rinex_parser_factory.hh"

#include "rinex/rinex_parser.hh"

namespace gnssxx {
namespace rinex {

rinex_parser::rinex_parser() {
}

rinex_parser::~rinex_parser() {
}

void rinex_parser::parse(std::istream &in) {
    rinex_parse_context ctx;
    // TODO return parsed doc?
}

} // namespace rinex
} // namespace gnssxx
