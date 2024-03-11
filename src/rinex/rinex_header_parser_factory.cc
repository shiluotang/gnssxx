#include <map>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

#include "rinex/rinex_header_parser.hh"

#include "rinex/rinex_header_parser_factory.hh"

namespace gnssxx {
namespace rinex {

std::shared_ptr<rinex_header_parser_factory>
rinex_header_parser_factory::instance() {
    static struct once {
        once() {
            _M_factory = std::shared_ptr<rinex_header_parser_factory>(
                    new rinex_header_parser_factory());
        }
        std::shared_ptr<rinex_header_parser_factory> _M_factory;
    } initialization;
    return initialization._M_factory;
}

rinex_header_parser_factory::~rinex_header_parser_factory() {
}

rinex_header_parser_factory::parser_ptr
rinex_header_parser_factory::get_parser(std::string const &label) {
    // label convert to 20 characters length
    std::string plabel = rinex_header_parser_factory::padding_label(label);
    map_type::const_iterator it = _M_parsers.find(plabel);
    if (it == _M_parsers.end())
        return nullptr;
    return it->second;
}

void rinex_header_parser_factory::set_parser(
        std::string const &label,
        parser_ptr parser) {
    // label convert to 20 characters length
    std::string plabel = rinex_header_parser_factory::padding_label(label);
    if (parser)
        _M_parsers[plabel] = parser;
    else
        _M_parsers.erase(plabel);
}

std::string
rinex_header_parser_factory::padding_label(std::string const& label) {
    // position [60, 79]
    std::vector<char> s(20, ' ');
    label.copy(&s[0], s.size(), 0);
    return std::string(s.begin(), s.end());
}

} // namespace rinex
} // namespace gnssxx
