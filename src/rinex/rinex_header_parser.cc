#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_file_type.hh"
#include "rinex/rinex_file_satsys.hh"
#include "rinex/rinex_header_parser_factory.hh"

#include "rinex/rinex_header_parser.hh"

namespace gnssxx {
namespace rinex {

rinex_header_parser::~rinex_header_parser() {
}

bool rinex_header_parser::parse(
        std::string const &content,
        rinex_file_header &header) {
    return false;
}

class header_first_line_parser
    : public virtual rinex_header_parser {
    public:
        virtual bool parse(
                std::string const &content,
                rinex_file_header &header) {
            double ver = 0.0;
            char type = 'G';
            char sys = 'M';
            int n = std::sscanf(
                    content.c_str(),
                    "%lf%*11c%c%*19c%c%*19c",
                    &ver,
                    &type,
                    &sys);
            if (n != 3)
                return false;
            int vmajor = static_cast<int>(ver);
            int vminor = static_cast<int>((ver - vmajor) * 100);
            header.set_version(rinex_file_version(vmajor, vminor));
            // FIXME handle unknown
            header.set_type(from_file_type_indicator(type));
            // FIXME handle unknown
            header.set_satsys(from_file_satsys_indicator(sys));
            return true;
        }
};

void rinex_header_parser::register_parsers() {
    rinex_header_parser_factory::instance()->set_parser(
            "RINEX VERSION / TYPE",
            std::make_shared<header_first_line_parser>());
}

} // namespace rinex
} // namespace gnssxx
