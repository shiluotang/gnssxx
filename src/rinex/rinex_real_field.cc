#include <istream>
#include <sstream>
#include <iomanip>
#include <string>

#include "misc/utils.hh"
#include "rinex/rinex_field.hh"

#include "rinex/rinex_real_field.hh"

namespace gnssxx {
namespace rinex {

rinex_real_field::rinex_real_field(
        int maxwidth,
        int precision,
        std::string scientific_notation)
    : rinex_field(maxwidth, precision)
    , _M_value(0)
    , _M_scientific_notation(scientific_notation)
{
}

rinex_real_field::~rinex_real_field() {
}

void rinex_real_field::scan(std::istream &in) {
    this->set_rawstr("");
    _M_value = value_type(0);
    std::string buffer(this->get_maxwidth(), 0);
    std::istream::sentry cerb(in, true);
    if (cerb) {
        in.get(&buffer[0], buffer.size() + 1);
        if (!in)
            return;
        buffer = buffer.substr(0, in.gcount());
    } else {
        buffer = "";
    }
    this->set_rawstr(buffer);
    // fortran scientific annotation "D" => "E"
    buffer = misc::replace_all(buffer, "D", "E");
    std::istringstream iss(buffer);
    iss >> _M_value;
    if (!iss) {
        // TODO
    }
}

void rinex_real_field::print(std::ostream &out) const {
    std::ostringstream oss;
    if (_M_scientific_notation.length() > 0)
        oss << std::scientific;
    if (std::isupper(_M_scientific_notation[0]))
        oss << std::uppercase;
    oss << std::setw(this->get_maxwidth());
    oss << std::setprecision(this->get_minwidth());
    oss << _M_value;
    out << oss.str();
}

rinex_real_field::value_type
rinex_real_field::value() const {
    return _M_value;
}

void rinex_real_field::set_value(
        value_type const &value) {
    _M_value = value;
}

double
rinex_real_field::F() const {
    return value();
}

} // namespace rinex
} // namespace gnssxx
