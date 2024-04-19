#ifndef GNSSXX_RINEX_RINEX_PARSER_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_PARSER_HH_INCLUDED

#include "rinex/rinex_file_header.hh"
#include "rinex/rinex_file.hh"

namespace gnssxx {
namespace rinex {

class rinex_parser {
    public:
        rinex_parser();
        virtual ~rinex_parser();
        virtual bool is_end_of_header(std::string const &line) const;
        virtual bool is_comment(std::string const &line) const;

        virtual bool parse(std::istream &in, bool skip_version = false);
        virtual bool parse_line(std::string const &line);
        virtual bool parse_header_line(std::string const &line);
    protected:
        bool _M_parsing_header;
        rinex_file_header _M_rinex_header;
    private:
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSER_HH_INCLUDED
