#include <istream>
#include <sstream>
#include <string>
#include <iostream>

#include "misc/utils.hh"
#include "rinex/rinex_field.hh"

#include "rinex/rinex_string_field.hh"

namespace gnssxx {
namespace rinex {

rinex_string_field::rinex_string_field(int maxwidth, int minwidth)
    : rinex_field(maxwidth, minwidth)
    , _M_value("")
{
}

rinex_string_field::~rinex_string_field() {
}

void rinex_string_field::scan(std::istream &in) {
    this->set_rawstr("");
    _M_value = "";
    std::string buffer(this->get_maxwidth(), 0);
    std::istream::sentry cerb(in, true);
    if (!cerb)
        return;
    if (!in.get(&buffer[0], buffer.size() + 1))
        return;
    buffer = buffer.substr(0, in.gcount());
    this->set_rawstr(buffer);
    _M_value = buffer;
}

void rinex_string_field::print(std::ostream &out) const {
    out << _M_value;
}

rinex_string_field::value_type
rinex_string_field::value() const {
    return _M_value;
}

void rinex_string_field::value(
        value_type const &value) {
    _M_value = value;
}

} // namespace rinex
} // namespace gnssxx
