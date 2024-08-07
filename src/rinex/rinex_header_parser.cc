#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_file_type.hh"
#include "rinex/rinex_file_satsys.hh"
#include "rinex/rinex_header_parser_factory.hh"
#include "rinex/rinex_file_header.hh"

#include "rinex/rinex_header_parser.hh"

namespace gnssxx {
namespace rinex {

rinex_header_parser::~rinex_header_parser() {
}

} // namespace rinex
} // namespace gnssxx
