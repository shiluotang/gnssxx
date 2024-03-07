#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctime>

#include "gnssxx.hpp"

int main(int argc, char *argv[]) try {
    using gnssxx::time::unixtime;
    using gnssxx::time::timezone;
    std::cout << "now = " << static_cast<time_t>(unixtime::now()) << std::endl;
    std::cout << "tz = " << timezone::offset() << std::endl;
    return EXIT_SUCCESS;
} catch (std::exception const &e) {
    std::cerr << "[C++ exception] " << e.what() << std::endl;
    return EXIT_FAILURE;
} catch (...) {
    std::cerr << "[C++ exception] " << "<UNKNOWN CAUSE>" << std::endl;
    return EXIT_FAILURE;
}
