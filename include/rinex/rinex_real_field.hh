#ifndef GNSSXX_RINEX_RINEX_REAL_FIELD_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_REAL_FIELD_HH_INCLUDED

#include <iosfwd>

#include "rinex/rinex_field.hh"

namespace gnssxx {
namespace rinex {

class rinex_real_field
    : public rinex_field {
    public:
        typedef double value_type;
        explicit
        rinex_real_field(
                int maxwidth,
                int precision = 6,
                std::string scientific_notation = "");
        virtual
        ~rinex_real_field();

        virtual
        void scan(std::istream&);
        virtual
        void print(std::ostream&) const;

        value_type value() const;
        void set_value(value_type const&);
    protected:
    private:
        value_type _M_value;
        std::string _M_scientific_notation;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_REAL_FIELD_HH_INCLUDED
