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
        rinex_file_type const &type) const {
    size_t index = static_cast<size_t>(type);
    if (index < 0 || index >= _M_typed_parsers.size())
        return nullptr;
    map_type::const_iterator it = _M_typed_parsers[index].find(version);
    if (it == _M_typed_parsers[index].end())
        return nullptr;
    return it->second;
}

void rinex_parser_factory::set_parser(
        rinex_file_version const &version,
        rinex_file_type const &type,
        std::shared_ptr<rinex_parser> parser) {
    size_t index = static_cast<size_t>(type);
    if (index < 0 || index >= _M_typed_parsers.size())
        _M_typed_parsers.resize(index + 1);
    _M_typed_parsers[index][version] = parser;
}

rinex_parser_factory::map_type::const_iterator
rinex_parser_factory::get_compat_parsers(
        rinex_file_version const &version,
        rinex_file_type const &type) const {
    size_t index = static_cast<size_t>(type);
    if (index < 0 || index >= _M_typed_parsers.size())
        return map_type::const_iterator();
    map_type::const_iterator it = _M_typed_parsers[index].lower_bound(version);
    if (it == _M_typed_parsers[index].end())
        return map_type::const_iterator();
    return it;
}

} // namespace rinex
} // namespace gnssxx
