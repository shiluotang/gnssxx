#ifndef GNSSXX_RINEX_RINEX_FIELD_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_FIELD_HH_INCLUDED

#include <iosfwd>
#include <string>

namespace gnssxx {
namespace rinex {

class rinex_field {
    public:
        explicit
        rinex_field(int, int = 0);

        rinex_field();

        virtual
        ~rinex_field();

        int get_maxwidth() const;
        void set_maxwidth(int);

        int get_minwidth() const;
        void set_minwidth(int);

        std::string get_rawstr() const;
        void set_rawstr(std::string const&);

        virtual
        void scan(std::istream&) = 0;

        virtual
        void print(std::ostream&) const = 0;
    protected:
    private:
        int _M_maxwidth;
        int _M_minwidth;
        std::string _M_rawstr;
};

std::istream& operator>>(std::istream&, rinex_field&);
std::istream& operator>>(std::istream&, rinex_field&&);

std::ostream& operator<<(std::ostream&, rinex_field const&);

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_FIELD_HH_INCLUDED
