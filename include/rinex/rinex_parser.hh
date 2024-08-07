#ifndef GNSSXX_RINEX_RINEX_PARSER_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_PARSER_HH_INCLUDED

#include <istream>

#include "rinex/rinex_parse_context.hh"

namespace gnssxx {
namespace rinex {

class rinex_parser {
    public:
        rinex_parser();
        virtual ~rinex_parser();

        void parse(std::istream&);

        void parse_meta(std::string const&, rinex_parse_context&);
    protected:
    private:
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSER_HH_INCLUDED
