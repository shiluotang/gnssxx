#ifndef GNSSXX_RINEX_RINEX_COMPOUND_FIELD_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_COMPOUND_FIELD_HH_INCLUDED

#include <vector>
#include <memory>

#include "rinex/rinex_field.hh"

namespace gnssxx {
namespace rinex {

class rinex_compound_field {
    public:
        typedef std::shared_ptr<gnssxx::rinex::rinex_field> field_ptr;

        void scan(std::istream &in);

        void print(std::ostream &out) const;

        field_ptr& operator[](size_t n);

        field_ptr const& operator[](size_t n) const;
    protected:
        rinex_compound_field(std::vector<field_ptr> fields);
    private:
        std::vector<field_ptr> _M_fields;
        friend class rinex_compound_field_builder;
};

std::istream& operator>>(std::istream&, rinex_compound_field&);
std::ostream& operator<<(std::ostream&, rinex_compound_field const&);

} // namespace rinex
} // namespace gnsxx

#endif // GNSSXX_RINEX_RINEX_COMPOUND_FIELD_HH_INCLUDED
