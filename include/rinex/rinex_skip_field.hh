#ifndef GNSSXX_RINEX_RINEX_SKIP_FIELD_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_SKIP_FIELD_HH_INCLUDED

#include <iosfwd>

#include "rinex/rinex_field.hh"

namespace gnssxx {
namespace rinex {

class rinex_skip_field
    : public rinex_field {
    public:
        explicit
        rinex_skip_field(int, int = 6);
        virtual
        ~rinex_skip_field();

        virtual
        void scan(std::istream&);
        virtual
        void print(std::ostream&) const;

        virtual
        std::string X() const;
    protected:
    private:
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_SKIP_FIELD_HH_INCLUDED
