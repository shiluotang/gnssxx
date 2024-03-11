#ifndef GNSSXX_RINEX_RINEX_HEADER_PARSER_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_HEADER_PARSER_HH_INCLUDED

#include <string>

#include "rinex/rinex_file_header.hh"

namespace gnssxx {
namespace rinex {

class rinex_header_parser {
    public:
        virtual ~rinex_header_parser();

        /**
         * parse one header line.
         *
         * @param[in] line input.
         * @param[in] header output.
         * @return {@code true} on success, vice versa.
         */
        virtual bool parse(
                std::string const &content,
                rinex_file_header &header) = 0;

        static void register_parsers();
    protected:
    private:
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_HEADER_PARSER_HH_INCLUDED
