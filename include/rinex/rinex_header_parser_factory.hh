#ifndef GNSSXX_RINEX_RINEX_HEADER_PARSER_FACTORY_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_HEADER_PARSER_FACTORY_HH_INCLUDED

#include <memory>
#include <string>
#include <map>

#include "rinex/rinex_header_parser.hh"

namespace gnssxx {
namespace rinex {

class rinex_header_parser_factory {
    public:
        typedef std::shared_ptr<rinex_header_parser> parser_ptr;
        typedef std::map<std::string, parser_ptr> map_type;

        virtual ~rinex_header_parser_factory();
        virtual parser_ptr get_parser(std::string const &label);
        virtual void set_parser(std::string const &label, parser_ptr);

        static
        std::shared_ptr<rinex_header_parser_factory> instance();
        static
        std::string padding_label(std::string const&, int = 20);
    protected:
    private:
        map_type _M_parsers;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_HEADER_PARSER_FACTORY_HH_INCLUDED
