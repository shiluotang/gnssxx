#ifndef GNSSXX_RINEX_RINEX_FILE_TYPE_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_FILE_TYPE_HH_INCLUDED

#include <iosfwd>

namespace gnssxx {
namespace rinex {

enum rinex_file_type {
    NAVMSG = 0,
    METEOR,
    OBSERV,
    UNKNOWN
};

rinex_file_type from_file_type_indicator(char c);

std::ostream& operator<<(std::ostream&, rinex_file_type const&);

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_FILE_TYPE_HH_INCLUDED
