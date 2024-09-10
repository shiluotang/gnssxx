#ifndef GNSSXX_RINEX_RINEX_PARSER_CONTEXT_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_PARSER_CONTEXT_HH_INCLUDED

#include "rinex/rinex_metadata.hh"
#include "rinex/rinex_file_header.hh"

namespace gnssxx {
namespace rinex {

class rinex_parse_context {
    public:
        virtual ~rinex_parse_context();

        rinex_metadata const& get_metadata() const;
        rinex_file_header const& get_header() const;
        rinex_metadata& get_metadata();
        rinex_file_header& get_header();

        void set_metadata(rinex_metadata const&);
        void set_header(rinex_file_header const&);

        // TODO What about data part?
        // TODO What about different header part?
    protected:
    private:
        rinex_metadata _M_metadata;
        rinex_file_header _M_header;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSER_CONTEXT_HH_INCLUDED
