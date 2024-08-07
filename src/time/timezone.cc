#include <ctime>
#include <cerrno>
#include <cstring>

#include <string>
#include <stdexcept>

#include "time/timezone.hh"

namespace {

int errno_code() {
    return errno;
}

std::string errno_message(int ecode = errno_code()) {
    return std::strerror(ecode);
}

} // namespace

namespace gnssxx {
namespace time {

int timezone::offset0() {
    // MinGW mktime before "1970-01-01 00:00:00 GMT" only yield -1.
    std::time_t const orig = 86400;
    // "1970-01-02 00:00:00 GMT"
    struct tm *ptr = std::gmtime(&orig);
    if (!ptr)
        throw std::runtime_error(errno_message());
    struct tm gmt = *ptr;
    // mktime converts parts into time_t taking account of timezone
    // which is "1970-01-02 00:00:00 +0800" => "1970-01-01 16:00:00 GMT"
    // orig("1970-01-02 00:00:00 GMT") - maked_time("1970-01-01 16:00:00 GMT")
    return std::difftime(orig, std::mktime(&gmt));
}

int timezone::offset() {
    static int off = offset0();
    return off;
}

} // namespace time
} // namespace gnssxx
