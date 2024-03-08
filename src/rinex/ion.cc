#include "rinex/ion.hh"

namespace gnssxx {
namespace rinex {

double ion::get_alpha(size_t n) const {
    return _M_alpha[n];
}

double ion::get_beta(size_t n) const {
    return _M_beta[n];
}

void ion::set_alpha(size_t n, double value) {
    _M_alpha[n] = value;
}

void ion::set_beta(size_t n, double value) {
    _M_beta[n] = value;
}

} // namespace rinex
} // namespace gnssxx
