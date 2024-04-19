#ifndef GNSSXX_RINEX_RINEX_PARSER_FACTORY_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_PARSER_FACTORY_HH_INCLUDED

#include <string>
#include <vector>
#include <map>

#include "rinex/rinex_parser.hh"
#include "rinex_file_version.hh"

namespace gnssxx {
namespace rinex {

class rinex_parser_factory {
    public:
        typedef std::shared_ptr<rinex_parser> parser_ptr;
        typedef std::map<rinex_file_version, parser_ptr> map_type;
        typedef std::vector<map_type> typed_parsers;

        static std::shared_ptr<rinex_parser_factory> instance();

        parser_ptr get_parser(
                rinex_file_version const&,
                rinex_file_type const&) const;
        void set_parser(
                rinex_file_version const&,
                rinex_file_type const &,
                parser_ptr);
        map_type::const_iterator get_compat_parsers(
                rinex_file_version const&,
                rinex_file_type const&) const;
    protected:
    private:
        typed_parsers _M_typed_parsers;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_PARSER_FACTORY_HH_INCLUDED
