#ifndef GNSSXX_RINEX_RINEX_INTEGER_FIELD_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_INTEGER_FIELD_HH_INCLUDED

#include <iosfwd>

#include "rinex/rinex_field.hh"

namespace gnssxx {
namespace rinex {

class rinex_integer_field
    : public rinex_field {
    public:
        typedef long value_type;
        explicit
        rinex_integer_field(int, char = '0');
        virtual
        ~rinex_integer_field();

        virtual
        void scan(std::istream&);

        virtual
        void print(std::ostream&) const;

        value_type value() const;
        void set_value(value_type const&);
    protected:
    private:
        value_type _M_value;
        char _M_fillchar;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_INTEGER_FIELD_HH_INCLUDED
