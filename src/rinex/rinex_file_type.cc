#include <ostream>

#include "rinex/rinex_file_type.hh"
#include "misc/utils.hh"

namespace gnssxx {
namespace rinex {

rinex_file_type rinex_file_type_of_indicator(char c) {
    switch (c) {
        case 'N': return NAVMSG;
        case 'M': return METEOR;
        case 'O': return OBSERV;
        default: break;
    }
    return UNKNOWN;
}

char rinex_file_type_to_indicator(rinex_file_type value) {
    char c = 'X';
    switch (value) {
        case NAVMSG: c = 'N'; break;
        case METEOR: c = 'M'; break;
        case OBSERV: c = 'O'; break;
        default: break;
    }
    return c;
}

ENUM_OS_BEGIN(rinex_file_type);
ENUM_OS_ITEM(NAVMSG);
ENUM_OS_ITEM(METEOR);
ENUM_OS_ITEM(OBSERV);
ENUM_OS_END(rinex_file_type);

} // namespace rinex
} // namespace gnssxx
