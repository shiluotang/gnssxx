#include <ostream>

#include "rinex/rinex_file_type.hh"
#include "misc/utils.hh"

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

ENUM_OS_BEGIN(rinex_file_type);
ENUM_OS_ITEM(NAVMSG);
ENUM_OS_ITEM(METEOR);
ENUM_OS_ITEM(OBSERV);
ENUM_OS_END(rinex_file_type);

} // namespace rinex
} // namespace gnssxx
