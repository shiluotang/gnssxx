#include <ostream>

#include "rinex//rinex_file_satsys.hh"

namespace gnssxx {
namespace rinex {

rinex_file_satsys from_file_satsys_indicator(char c) {
    switch (c) {
        case ' ' :
        case 'G' : return GPS;
        case 'R' : return GLONASS;
        case 'E' : return GALILEO;
        case 'J' : return QZSS;
        case 'C' : return BDS;
        case 'S' : return SBAS;
        case 'T' : return TRANSIT;
        case 'M' : return MIXED;
        default: break;
    }
    return MIXED;
}

std::ostream& operator<<(std::ostream &out, rinex_file_satsys const &value) {
    char const *name = "UNKNOWN";
    switch (value) {
        case GPS: name = "GPS"; break;
        case GLONASS: name = "GLONASS"; break;
        case GALILEO: name = "GALILEO"; break;
        case QZSS: name = "QZSS"; break;
        case BDS: name = "BDS"; break;
        case SBAS: name = "SBAS"; break;
        case TRANSIT: name = "TRANSIT"; break;
        case MIXED: name = "MIXED"; break;
        default: break;
    }
    out << name << "(" << static_cast<int>(value) << ")";
    return out;
}

} // namespace rinex
} // namespace gnssxx
