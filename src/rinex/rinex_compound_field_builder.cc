#include <vector>

#include "rinex/rinex_field.hh"
#include "rinex/rinex_integer_field.hh"
#include "rinex/rinex_real_field.hh"
#include "rinex/rinex_string_field.hh"
#include "rinex/rinex_skip_field.hh"

#include "rinex/rinex_compound_field_builder.hh"

namespace gnssxx {
namespace rinex {

rinex_compound_field_builder&
rinex_compound_field_builder::F(
        int width,
        int precision,
        std::string notation) {
    _M_fields.push_back(std::make_shared<f>(width, precision, notation));
    return *this;
}

rinex_compound_field_builder&
rinex_compound_field_builder::I(int width) {
    _M_fields.push_back(std::make_shared<i>(width));
    return *this;
}

rinex_compound_field_builder&
rinex_compound_field_builder::A(int width) {
    _M_fields.push_back(std::make_shared<a>(width));
    return *this;
}

rinex_compound_field_builder&
rinex_compound_field_builder::X(int width) {
    _M_fields.push_back(std::make_shared<x>(width));
    return *this;
}

rinex_compound_field
rinex_compound_field_builder::build() {
    return rinex_compound_field(_M_fields);
}

} // namespace rinex
} // namespace gnssxx
