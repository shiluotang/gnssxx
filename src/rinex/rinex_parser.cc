#include <string>
#include <istream>
#include <sstream>
#include <iomanip>
#include <vector>

#include "rinex/rinex_file_header.hh"
#include "rinex/rinex_file_satsys.hh"
#include "rinex/rinex_file_type.hh"
#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_parse_context.hh"
#include "rinex/rinex_header_parser_factory.hh"
#include "rinex/rinex_parser_factory.hh"
#include "rinex/rinex_compound_field_builder.hh"
#include "rinex/rinex_compound_field.hh"
#include "misc/istream_line_iterator.hh"

#include "rinex/rinex_parser.hh"

namespace gnssxx {
namespace rinex {

rinex_parser::rinex_parser() {
}

rinex_parser::~rinex_parser() {
}

void rinex_parser::parse(std::istream &in) {
    using misc::istream_line_iterator;
    rinex_parse_context ctx;
    istream_line_iterator it(&in);
    istream_line_iterator eos;
    if (it == eos)
        return;
    if (!this->parse_metadata(*it++, ctx.get_metadata())) {
        // TODO handle failure
    }
    for (; it != eos; ++it) {
        // TODO parse data.
    }
    // FIXME TODO return parsed doc?
}

bool rinex_parser::parse_metadata(
        std::string const &line,
        rinex_metadata &metadata) {
    std::string label = pad_label(line.substr(60));
    if (label != pad_label("RINEX VERSION / TYPE"))
        return false;
    rinex_compound_field f = rinex_compound_field_builder()
        .F(9, 2).X(11)
        .A(1).X(19)
        .A(1).X(19)
        .build();
    std::istringstream iss(line);
    // FIXME handle parse failure
    iss >> f;
    metadata.set_version(rinex_file_version(f[0]->F()));
    metadata.set_type(rinex_file_type_of_indicator(f[2]->A()[0]));
    metadata.set_satsys(rinex_file_satsys_of_indicator(f[4]->A()[0]));
    return true;
}

std::string rinex_parser::pad_label(std::string const &label) {
    return rinex_header_parser_factory::padding_label(label);
}

} // namespace rinex
} // namespace gnssxx
