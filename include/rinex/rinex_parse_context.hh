#ifndef GNSSXX_RINEX_RINEX_PARSER_CONTEXT_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_PARSER_CONTEXT_HH_INCLUDED

#include "rinex/rinex_metadata.hh"
#include "rinex/rinex_file_header.hh"

namespace gnssxx {
namespace rinex {

class rinex_parse_context {
    public:
        virtual ~rinex_parse_context();
    protected:
    private:
        rinex_metadata _M_metadata;
        rinex_file_header _M_header;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSER_CONTEXT_HH_INCLUDED
