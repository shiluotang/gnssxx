#include "rinex/rinex_file_type.hh"

namespace gnssxx {
namespace rinex {

rinex_file_type from_type_indicator(char c) {
    switch (c) {
        case 'N': return NAVMSG;
        case 'M': return METEOR;
        case 'O': return OBSERV;
        default: break;
    }
    return UNKNOWN;
}

} // namespace rinex
} // namespace gnssxx
