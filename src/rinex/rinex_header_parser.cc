#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_file_type.hh"
#include "rinex/rinex_file_satsys.hh"
#include "rinex/rinex_header_parser_factory.hh"
#include "rinex/rinex_file_header.hh"

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

class rinex_version_type_parser
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

class pgm_runby_date_parser
    : public virtual rinex_header_parser {
    public:
        virtual bool parse(
                std::string const &content,
                rinex_file_header &header) {
            std::vector<char> pbuf(20 + 1);
            std::vector<char> rbuf(20 + 1);
            std::vector<char> dbuf(20 + 1);
            int n = std::sscanf(
                    content.c_str(),
                    "%20c%20c%20c",
                    &pbuf[0],
                    &rbuf[0],
                    &dbuf[0]);
            if (n != 3)
                return false;
            header.set_pgm(&pbuf[0]);
            header.set_run_by(&rbuf[0]);
            header.set_date(&dbuf[0]);
            return true;
        }
    protected:
    private:
};

class ion_alpha_parser
    : public virtual rinex_header_parser {
    public:
        struct double_float_notation_filter {
            char operator()(char c) {
                return ::toupper(c) == 'D' ? 'E' : c;
            }
        };
        virtual bool parse(
                std::string const &content,
                rinex_file_header &header) {
            double alpha[4];
            // modify scientific notation any "D" => "E"
            std::string filtered_content = content;
            std::transform(
                    filtered_content.begin(),
                    filtered_content.end(),
                    filtered_content.begin(),
                    double_float_notation_filter());
            int n = std::sscanf(
                    &filtered_content[0],
                    "%*2c%12lf%12lf%12lf%12lf",
                    &alpha[0],
                    &alpha[1],
                    &alpha[2],
                    &alpha[3]);
            if (n != 4)
                return false;
            ion iono;
            if (header.has_ion())
                iono = header.get_ion();
            iono.set_alpha(0, alpha[0]);
            iono.set_alpha(1, alpha[1]);
            iono.set_alpha(2, alpha[2]);
            iono.set_alpha(3, alpha[3]);
            header.set_ion(iono);
            return true;
        }
    protected:
    private:
};

class ion_beta_parser
    : public virtual rinex_header_parser {
    public:
        struct double_float_notation_filter {
            char operator()(char c) {
                return ::toupper(c) == 'D' ? 'E' : c;
            }
        };
        virtual bool parse(
                std::string const &content,
                rinex_file_header &header) {
            double beta[4];
            // modify scientific notation any "D" => "E"
            std::string filtered_content = content;
            std::transform(
                    filtered_content.begin(),
                    filtered_content.end(),
                    filtered_content.begin(),
                    double_float_notation_filter());
            int n = std::sscanf(
                    &filtered_content[0],
                    "%*2c%12lf%12lf%12lf%12lf",
                    &beta[0],
                    &beta[1],
                    &beta[2],
                    &beta[3]);
            if (n != 4)
                return false;
            ion iono;
            if (header.has_ion())
                iono = header.get_ion();
            iono.set_beta(0, beta[0]);
            iono.set_beta(1, beta[1]);
            iono.set_beta(2, beta[2]);
            iono.set_beta(3, beta[3]);
            header.set_ion(iono);
            return true;
        }
    protected:
    private:
};

class leap_seconds_parser
    : public virtual rinex_header_parser {
    public:
        virtual bool parse(
                std::string const &content,
                rinex_file_header &header) {
            int cur = 0;
            int n = std::sscanf(
                    content.c_str(),
                    "%6d",
                    &cur);
            if (n < 1)
                return false;
            header.set_leap_seconds(cur);
            return true;
        }
    protected:
    private:
};

void rinex_header_parser::register_parsers() {
#ifdef REGISTER_PARSER
#   undef REGISTER_PARSER
#endif
#define REGISTER_PARSER(name, type) \
    do { \
    rinex_header_parser_factory::instance()->set_parser( \
            name, \
            std::make_shared<type>()); \
    } while (false)
    REGISTER_PARSER("RINEX VERSION / TYPE", rinex_version_type_parser);
    REGISTER_PARSER("PGM / RUN BY / DATE", pgm_runby_date_parser);
    REGISTER_PARSER("ION ALPHA", ion_alpha_parser);
    REGISTER_PARSER("ION BETA", ion_beta_parser);
    REGISTER_PARSER("LEAP SECONDS", leap_seconds_parser);
#undef REGISTER_PARSER
}

} // namespace rinex
} // namespace gnssxx
