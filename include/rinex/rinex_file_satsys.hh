#ifndef GNSSXX_RINEX_RINEX_FILE_SATSYS_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_FILE_SATSYS_HH_INCLUDED

#include <iosfwd>

namespace gnssxx {
namespace rinex {

enum rinex_file_satsys {
    GPS,
    GLONASS,
    GALILEO,
    QZSS,
    BDS,
    SBAS,
    MIXED,
    TRANSIT,
};

rinex_file_satsys from_file_satsys_indicator(char c);

std::ostream& operator<<(std::ostream&, rinex_file_satsys const&);

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_FILE_SATSYS_HH_INCLUDED
