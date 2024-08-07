#include "misc/utils.hh"

namespace gnssxx {
namespace misc {

std::string& replace_all(
        std::string &s,
        std::string const &lookup,
        std::string const &replacement) {
    for (std::string::size_type pos = s.find(lookup, 0);
            pos != std::string::npos;
            pos = s.find(lookup, pos + replacement.length())) {
        s.replace(pos, lookup.length(), replacement);
    }
    return s;
}

std::string replace_all(
        std::string const &s,
        std::string const &lookup,
        std::string const &replacement) {
    std::string copy(s);
    return replace_all(copy, lookup, replacement);
}

} // namespace misc
} // namespace gnssxx
