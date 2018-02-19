#include <limits>
#include <stdexcept>
#include <iomanip>
#include <ostream>
#include <istream>
#include <iostream>
#include <string>
#include <cmath>

#include "../misc/decimal.hpp"
#include "../misc/utils.hpp"

#include "unixtime.hpp"

namespace {
    static const double UNIX_EPOCH_JULIAN_DATE = 2440587.5;
}

namespace gnssxx {

    unixtime::unixtime(std::time_t t) :_M_seconds(t) {}

    unixtime::unixtime(double t) : _M_seconds(t) {}

    unixtime::unixtime(std::time_t t, double fraction) : _M_seconds(t + fraction) { }

    unixtime::~unixtime() {}

    unixtime unixtime::now() {
        time_t time = 0;
        if (static_cast<time_t>(-1) == std::time(&time))
            throw std::runtime_error("failed to retrieve unix time!");
        return unixtime(time);
    }

    unixtime unixtime::from_jd(double jd) {
        return unixtime((jd - UNIX_EPOCH_JULIAN_DATE) * 86400);
    }

    unixtime& unixtime::operator = (unixtime const &other) {
        this->_M_seconds = other._M_seconds;
        return *this;
    }
}
