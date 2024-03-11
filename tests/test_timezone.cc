#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctime>

#include "gnssxx.hpp"

#include "gtest/gtest.h"

TEST(timezone_test, current_tz) {
    using gnssxx::time::unixtime;
    using gnssxx::time::timezone;
    std::cout << "now = " << static_cast<time_t>(unixtime::now()) << std::endl;
    std::cout << "tz = " << timezone::offset() << std::endl;
}
