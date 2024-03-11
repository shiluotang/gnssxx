#include "rinex/rinex_parser_factory.hh"

namespace gnssxx {
namespace rinex {

std::shared_ptr<rinex_parser_factory>
rinex_parser_factory::instance() {
    static struct once {
        once()
            : _M_factory(new rinex_parser_factory())
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

rinex_parser_factory::parser_ptr
rinex_parser_factory::get_parser(
        rinex_file_version const &version,
        rinex_file_type const &type) {
    // TODO not implemented
    return NULL;
}

void rinex_parser_factory::set_parser(
        rinex_file_version const &version,
        rinex_file_type const &type,
        std::shared_ptr<rinex_parser> parser) {
    // TODO not implemented
}

} // namespace rinex
} // namespace gnssxx
