#include <string>
#include <istream>
#include <iomanip>
#include <vector>

#include "rinex/rinex_file_header.hh"
#include "rinex/rinex_file_satsys.hh"
#include "rinex/rinex_file_type.hh"
#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_header_parser_factory.hh"
#include "rinex/rinex_parser_factory.hh"

#include "rinex/rinex_parser.hh"

namespace gnssxx {
namespace rinex {

rinex_parser::rinex_parser()
    :_M_parsing_header(true)
{
}

rinex_parser::~rinex_parser() {
}

bool rinex_parser::is_end_of_header(
        std::string const &line) const {
    return line.find("END OF HEADER") == 60;
}

bool rinex_parser::is_comment(
        std::string const &line) const {
    return line.find("COMMENT") == 60;
}

bool rinex_parser::parse(std::istream &in, bool skip_version) {
    std::string line;
    std::string buffer(80, 0);
    while (std::getline(in, line, '\n')) {
        // padding or truncate to 80 characters line.
        line.copy(&buffer[0], buffer.size(), 0);
        if (!this->parse_line(buffer))
            return false;
    }
    return !in.bad() && !in.fail();
}

bool rinex_parser::parse_header_line(std::string const &line) {
    std::string const &content = line.substr(0, 60);
    std::string const &label = line.substr(60);

    rinex_header_parser_factory::parser_ptr parser =
        rinex_header_parser_factory::instance()->get_parser(label);
    if (!parser)
        return false;
    return parser->parse(content, this->_M_rinex_header);
}

bool rinex_parser::parse_line(std::string const &line) {
    // state machine!!!
    if (this->_M_parsing_header) {
        if (this->is_end_of_header(line)) {
            // header complete, next line is body
            this->_M_parsing_header = false;
        } else if (this->is_comment(line)) {
            // TODO ignore comment?
        } else {
            if (!this->parse_header_line(line))
                return false;
        }
    } else {
    }
    return false;
}

} // namespace rinex
} // namespace gnssxx
