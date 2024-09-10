#include <istream>
#include <sstream>
#include <string>

#include "misc/utils.hh"
#include "rinex/rinex_field.hh"

#include "rinex/rinex_skip_field.hh"

namespace gnssxx {
namespace rinex {

rinex_skip_field::rinex_skip_field(int maxwidth, int minwidth)
    : rinex_field(maxwidth, minwidth)
{
}

rinex_skip_field::~rinex_skip_field() {
}

void rinex_skip_field::scan(std::istream &in) {
    this->set_rawstr("");
    std::string buffer(this->get_maxwidth(), 0);
    std::istream::sentry cerb(in, true);
    if (!cerb)
        return;
    if (!in.get(&buffer[0], buffer.size() + 1))
        return;
    buffer = buffer.substr(0, in.gcount());
    this->set_rawstr(buffer);
}

void rinex_skip_field::print(std::ostream &out) const {
    out << std::string(this->get_maxwidth(), ' ');
}

std::string
rinex_skip_field::X() const {
    return this->get_rawstr();
}

} // namespace rinex
} // namespace gnssxx
