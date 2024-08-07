#ifndef GNSSXX_RINEX_RINEX_PARSE_OBS_CONTEXT_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_PARSE_OBS_CONTEXT_HH_INCLUDED

#include "rinex/rinex_parse_context.hh"

namespace gnssxx {
namespace rinex {

class rinex_parse_obs_context
    : public rinex_parse_context {
        public:
            virtual ~rinex_parse_obs_context();
        protected:
        private:

};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSE_OBS_CONTEXT_HH_INCLUDED
