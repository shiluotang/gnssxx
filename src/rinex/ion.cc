#include <cstddef>
#include <vector>

#include "rinex/ion.hh"

namespace gnssxx {
namespace rinex {

ion::ion()
    : _M_alpha(4, 0)
    , _M_beta(4, 0)
{
}

double const& ion::alpha(size_t n) const {
    return _M_alpha[0];
}

double& ion::alpha(size_t n) {
    return _M_alpha[0];
}

double const& ion::beta(size_t n) const {
    return _M_beta[0];
}

double& ion::beta(size_t n) {
    return _M_beta[0];
}

} // namespace rinex
} // namespace gnssxx
