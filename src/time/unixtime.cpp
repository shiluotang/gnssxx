#include <limits>
#include <stdexcept>
#include <iomanip>
#include <ostream>
#include <istream>
#include <iostream>
#include <string>
#include <cmath>

#include "unixtime.hpp"
#include "../misc/decimal.hpp"

namespace {
    static const double UNIX_EPOCH_JULIAN_DATE = 2440587.5;
}

namespace gnssxx {

    unixtime::unixtime(std::time_t t) :_M_time(t), _M_fraction(0) { }

    unixtime::unixtime(double t)
        : _M_time(static_cast<time_t>(t)),
        _M_fraction(t - static_cast<time_t>(t)) {
    }

    unixtime::unixtime(std::time_t t, double fraction)
        : _M_time(t + static_cast<time_t>(fraction)),
        _M_fraction(fraction - static_cast<time_t>(fraction)) {
    }

    unixtime::~unixtime() {}

    unixtime unixtime::now() {
        time_t time = 0;
        if (static_cast<time_t>(-1) == std::time(&time))
            throw std::runtime_error("failed to retrieve unix time!");
        return unixtime(time);
    }

    unixtime unixtime::fromJD(double jd) {
        return unixtime((jd - UNIX_EPOCH_JULIAN_DATE) * 86400);
    }

    unixtime& unixtime::operator = (unixtime const &other) {
        this->_M_time = other._M_time;
        this->_M_fraction = other._M_fraction;
        return *this;
    }
}
