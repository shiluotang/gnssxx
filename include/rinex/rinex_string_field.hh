#ifndef GNSSXX_RINEX_RINEX_STRING_FIELD_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_STRING_FIELD_HH_INCLUDED

#include <iosfwd>
#include <string>

#include "rinex/rinex_field.hh"

namespace gnssxx {
namespace rinex {

class rinex_string_field
    : public rinex_field {
    public:
        typedef std::string value_type;
        explicit
        rinex_string_field(int, int = 6);
        virtual
        ~rinex_string_field();

        virtual
        void scan(std::istream&);
        virtual
        void print(std::ostream&) const;

        value_type value() const;
        void value(value_type const&);
    protected:
    private:
        value_type _M_value;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_STRING_FIELD_HH_INCLUDED
