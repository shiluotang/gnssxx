#include <cstddef>
#include <ostream>

#include "misc/utils.hh"
#include "rinex/rinex_file_satsys.hh"

namespace gnssxx {
namespace rinex {

rinex_file_satsys rinex_file_satsys_of_indicator(char c) {
    switch (c) {
        case ' ' :
        case 'G' : return GPS;
        case 'R' : return GLONASS;
        case 'E' : return GALILEO;
        case 'J' : return QZSS;
        case 'C' : return BDS;
        case 'I' : return IRNSS;
        case 'S' : return SBAS;
        case 'M' : return MIXED;
        case 'T' : return TRANSIT;
        default: break;
    }
    return MIXED;
}

char rinex_file_satsys_to_indicator(rinex_file_satsys satsys) {
    static char INDICATORS[] = { "GREJCISMT" };
    char c = 'M';
    size_t idx = static_cast<size_t>(satsys);
    if (idx < std::char_traits<char>::length(INDICATORS))
        c = INDICATORS[idx];
    return c;
}

ENUM_OS_BEGIN(rinex_file_satsys);
ENUM_OS_ITEM(GPS);
ENUM_OS_ITEM(GLONASS);
ENUM_OS_ITEM(GALILEO);
ENUM_OS_ITEM(QZSS);
ENUM_OS_ITEM(BDS);
ENUM_OS_ITEM(SBAS);
ENUM_OS_ITEM(TRANSIT);
ENUM_OS_ITEM(MIXED);
ENUM_OS_END(rinex_file_satsys);

} // namespace rinex
} // namespace gnssxx
