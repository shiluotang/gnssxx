#include "rinex/rinex_field.hh"

namespace gnssxx {
namespace rinex {

rinex_field::rinex_field(int maxwidth, int minwidth)
    : _M_maxwidth(maxwidth)
    , _M_minwidth(minwidth)
    , _M_rawstr("")
{
}

rinex_field::rinex_field()
    : _M_maxwidth(0)
    , _M_minwidth(0)
    , _M_rawstr("")
{
}

rinex_field::~rinex_field() {
}

int rinex_field::get_maxwidth() const {
    return _M_maxwidth;
}

void rinex_field::set_maxwidth(int value) {
    _M_maxwidth = value;
}

int rinex_field::get_minwidth() const {
    return _M_minwidth;
}

void rinex_field::set_minwidth(int value) {
    _M_minwidth = value;
}

std::string rinex_field::get_rawstr() const {
    return _M_rawstr;
}

void rinex_field::set_rawstr(std::string const &value) {
    _M_rawstr = value;
}

void rinex_field::scan(std::istream&) {
    // Do nothing in base class
}

void rinex_field::print(std::ostream&) const {
    // Do nothing in base class
}

std::istream& operator>>(std::istream &in, rinex_field &f) {
    f.scan(in);
    return in;
}

std::istream& operator>>(std::istream &in, rinex_field &&f) {
    f.scan(in);
    return in;
}

std::ostream& operator<<(std::ostream &out, rinex_field const &f) {
    f.print(out);
    return out;
}

} // namespace rinex
} // namespace gnssxx
