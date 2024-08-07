#ifndef GNSSXX_RINEX_RINEX_HEADER_PARSER_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_HEADER_PARSER_HH_INCLUDED

#include <string>

#include "rinex/rinex_parse_context.hh"

namespace gnssxx {
namespace rinex {

class rinex_header_parser {
    public:
        virtual ~rinex_header_parser();

        virtual bool parse(
                std::string const &content,
                rinex_parse_context &ctx) = 0;
    protected:
    private:
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_HEADER_PARSER_HH_INCLUDED
