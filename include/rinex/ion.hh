#ifndef GNSSXX_RINEX_ION_HH_INCLUDED
#define GNSSXX_RINEX_ION_HH_INCLUDED

#include <cstdlib>

namespace gnssxx {
namespace rinex {

class ion {
    public:
        double get_alpha(size_t n) const;
        double get_beta(size_t n) const;
        void set_alpha(size_t n, double value);
        void set_beta(size_t n, double value);
    protected:
    private:
        double _M_alpha[4];
        double _M_beta[4];
};



} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_ION_HH_INCLUDED
