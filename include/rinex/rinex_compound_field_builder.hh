#ifndef GNSSXX_RINEX_RINEX_COMPOUND_FIELD_BUILDER_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_COMPOUND_FIELD_BUILDER_HH_INCLUDED

#include <vector>

#include "rinex/rinex_compound_field.hh"

namespace gnssxx {
namespace rinex {

class rinex_real_field;
class rinex_integer_field;
class rinex_string_field;
class rinex_skip_field;

class rinex_compound_field_builder {
    public:
        typedef rinex_compound_field::field_ptr field_ptr;
        using ff = rinex_field;
        using f = rinex_real_field;
        using i = rinex_integer_field;
        using a = rinex_string_field;
        using x = rinex_skip_field;

        rinex_compound_field_builder& F(
                int width,
                int precision = 6,
                std::string notation = "");
        rinex_compound_field_builder& I(int width);
        rinex_compound_field_builder& A(int width);
        rinex_compound_field_builder& X(int width);

        rinex_compound_field build();
    protected:
    private:
        std::vector<field_ptr> _M_fields;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_COMPOUND_FIELD_BUILDER_HH_INCLUDED
