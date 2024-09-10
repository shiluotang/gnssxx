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

rinex_file_type rinex_file_type_of_indicator(char);
char rinex_file_type_to_indicator(rinex_file_type);

std::ostream& operator<<(std::ostream&, rinex_file_type const&);

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_FILE_TYPE_HH_INCLUDED
