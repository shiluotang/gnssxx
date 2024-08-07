#include <istream>
#include <sstream>
#include <iomanip>
#include <string>

#include "rinex/rinex_field.hh"

#include "rinex/rinex_integer_field.hh"

namespace gnssxx {
namespace rinex {

rinex_integer_field::rinex_integer_field(int maxwidth, char fillchar)
    : rinex_field(maxwidth, 0)
    , _M_value(0)
    , _M_fillchar(fillchar)
{
}

rinex_integer_field::~rinex_integer_field() {
}

void rinex_integer_field::scan(std::istream &in) {
    this->set_rawstr("");
    _M_value = value_type(0);
    std::string buffer(this->get_maxwidth(), 0);
    std::istream::sentry cerb(in, true);
    if (!cerb)
        return;
    if (!in.get(&buffer[0], buffer.size() + 1))
        return;
    buffer = buffer.substr(0, in.gcount());
    this->set_rawstr(buffer);
    std::istringstream iss(buffer);
    iss >> _M_value;
    if (!iss) {
        // TODO
    }
}

void rinex_integer_field::print(std::ostream &out) const {
    std::ostringstream oss;
    oss
        << std::setw(this->get_maxwidth())
        << std::setfill(_M_fillchar)
        << _M_value;
    out << oss.str();
}

rinex_integer_field::value_type
rinex_integer_field::value() const {
    return _M_value;
}

void rinex_integer_field::set_value(
        value_type const &value) {
    _M_value = value;
}

} // namespace rinex
} // namespace gnssxx
