#ifndef GNSSXX_RINEX_RINEX_FILE_TYPE_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_FILE_TYPE_HH_INCLUDED

namespace gnssxx {
namespace rinex {

enum rinex_file_type {
    NAVMSG = 0,
    METEOR,
    OBSERV,
    UNKNOWN
};

rinex_file_type from_type_indicator(char c);

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_FILE_TYPE_HH_INCLUDED
