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
        virtual bool parse_version_type(
                std::istream &s,
                rinex_file_version &ver,
                std::string &type);

        virtual bool parse(std::istream &in, rinex_file &file);
    protected:
        bool _M_parsing_header;
    private:
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSER_HH_INCLUDED
