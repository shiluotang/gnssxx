#ifndef GNSSXX_RINEX_RINEX_PARSER_FACTORY_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_PARSER_FACTORY_HH_INCLUDED

#include <map>

#include "rinex/rinex_parser.hh"
#include "rinex_file_version.hh"

namespace gnssxx {
namespace rinex {

class rinex_parser_factory {
    public:
        typedef std::shared_ptr<rinex_parser> parser_ptr;
        typedef std::map<rinex_file_version, parser_ptr> map_type;

        static std::shared_ptr<rinex_parser_factory> instance();

        parser_ptr get_parser(
                rinex_file_version const&,
                rinex_file_type const& type);
        void set_parser(
                rinex_file_version const&,
                rinex_file_type const &type,
                parser_ptr parser);
    protected:
    private:
        map_type _M_parsers;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSER_FACTORY_HH_INCLUDED
