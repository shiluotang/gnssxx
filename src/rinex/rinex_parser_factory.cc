#include "rinex/rinex_parser_factory.hh"

namespace gnssxx {
namespace rinex {

std::shared_ptr<rinex_parser_factory>
rinex_parser_factory::instance() {
    static struct once {
        once()
            : _M_factory(new rinex_parser_factory)
        {
        }
        ~once() {
        }
        std::shared_ptr<rinex_parser_factory> _M_factory;
    } initialization;
    // static std::shared_ptr<rinex_parser_factory> f =
    //     std::shared_ptr<rinex_parser_factory>(new rinex_parser_factory());
    return initialization._M_factory;
}

std::shared_ptr<rinex_parser>
rinex_parser_factory::for_version(int major, int minor) {
    using namespace std::rel_ops;
    rinex_file_version v(major, minor);
    for (map_type::iterator it = _M_parsers.lower_bound(v);
            it != _M_parsers.end(); ++it) {
        if (!it->second)
            continue;
        return it->second;
    }
    return NULL;
}

rinex_parser_factory::parser_ptr
rinex_parser_factory::get_parser(int major, int minor, char type) {
    // TODO not implemented
    return NULL;
}

void rinex_parser_factory::set_parser(
        int major, int minor,
        std::shared_ptr<rinex_parser> parser) {
    _M_parsers[rinex_file_version(major, minor)] = parser;
}

void rinex_parser_factory::set_parser(
        int major, int minor, char type, parser_ptr parser) {
    // TODO not implemented
}


} // namespace rinex
} // namespace gnssxx
