#include <ctime>

#include <stdexcept>

#include "timezone.hpp"

namespace gnssxx {
    namespace time {
        int timezone::offset0() {
            using namespace std;
            // MinGW mktime before "1970-01-01 00:00:00 GMT" only yield -1.
            time_t const orig = 86400;
            struct tm *ptr = gmtime(&orig);
            if (!ptr)
                throw std::runtime_error("gmtime failed!");
            struct tm gmt = *ptr;
            return difftime(orig, mktime(&gmt));
        }

        int timezone::offset() {
            static int off = offset0();
            return off;
        }
    }
}
