#ifndef GNSSXX_RINEX_ION_HH_INCLUDED
#define GNSSXX_RINEX_ION_HH_INCLUDED

#include <cstddef>
#include <vector>

namespace gnssxx {
namespace rinex {

class ion {
    public:
        ion();
        double const& alpha(size_t n) const;
        double& alpha(size_t n);
        double const& beta(size_t n) const;
        double& beta(size_t n);
    protected:
    private:
        std::vector<double> _M_alpha;
        std::vector<double> _M_beta;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_ION_HH_INCLUDED
