#include "rinex/rinex_compound_field.hh"

namespace gnssxx {
namespace rinex {

void rinex_compound_field::scan(std::istream &in) {
    for (auto &f : _M_fields)
        f->scan(in);
}

void rinex_compound_field::print(std::ostream &out) const {
    for (auto &f : _M_fields)
        f->print(out);
}

rinex_compound_field::field_ptr&
rinex_compound_field::operator[](size_t n) {
    return _M_fields[n];
}

rinex_compound_field::field_ptr const&
rinex_compound_field::operator[](size_t n) const {
    return _M_fields[n];
}

rinex_compound_field::rinex_compound_field(
        std::vector<field_ptr> const &fields)
    : _M_fields(fields)
{
}

std::istream& operator>>(std::istream &in, rinex_compound_field &f) {
    f.scan(in);
    return in;
}

std::ostream& operator<<(std::ostream &out, rinex_compound_field const &f) {
    f.print(out);
    return out;
}

} // namespace rinex
} // namespace gnssxx
