#include <ostream>

#include "rinex/rinex_file_type.hh"

namespace gnssxx {
namespace rinex {

rinex_file_type from_file_type_indicator(char c) {
    switch (c) {
        case 'N': return NAVMSG;
        case 'M': return METEOR;
        case 'O': return OBSERV;
        default: break;
    }
    return UNKNOWN;
}

std::ostream& operator<<(std::ostream &out, rinex_file_type const &value) {
    char const *name = "UNKNOWN";
    switch (value) {
        case NAVMSG: name = "NAVMSG"; break;
        case METEOR: name = "METEOR"; break;
        case OBSERV: name = "OBSERV"; break;
        default: break;
    }
    out << name << "(" << static_cast<int>(value) << ")";
    return out;
}

} // namespace rinex
} // namespace gnssxx
