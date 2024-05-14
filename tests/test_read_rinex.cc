#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cctype>

#include <map>
#include <iomanip>
#include <sstream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "gnssxx.hpp"
#include "rinex/rinex_parser_factory.hh"
#include "rinex/rinex_header_parser_factory.hh"

#include "gtest/gtest.h"

TEST(rinex_test, test_parse_first_line) {
    using gnssxx::rinex::rinex_parser_factory;
    using gnssxx::rinex::rinex_header_parser;
    using gnssxx::rinex::rinex_header_parser_factory;
    using gnssxx::rinex::rinex_file_header;
    typedef rinex_header_parser_factory::parser_ptr parser_ptr;

    std::string line = "     2.11           N: GPS NAV DATA                         RINEX VERSION / TYPE";
    rinex_header_parser::register_parsers();
    parser_ptr parser = rinex_header_parser_factory::instance()
        ->get_parser("RINEX VERSION / TYPE");
    ASSERT_NE(parser, nullptr);
    rinex_file_header header;
    ASSERT_TRUE(parser->parse(line, header));
    std::cout << "RINEX VERSION = " << header.get_version() << std::endl;
    std::cout << "RINEX TYPE    = " << header.get_type() << std::endl;
    std::cout << "RINEX SAT SYS = " << header.get_satsys() << std::endl;
    line = "NetR9 5.56          Receiver Operator   28-FEB-24 00:00:00  PGM / RUN BY / DATE ";
    parser = rinex_header_parser_factory::instance()
        ->get_parser("PGM / RUN BY / DATE");
    ASSERT_NE(parser, nullptr);
    ASSERT_TRUE(parser->parse(line, header));
    std::cout << "PGM    = [" << header.get_pgm() << "]" << std::endl;
    std::cout << "RUN BY = [" << header.get_run_by() << "]" << std::endl;
    std::cout << "DATE   = [" << header.get_date() << "]" << std::endl;
}

TEST(rinex_test, test_parser_factory) {
    using gnssxx::rinex::rinex_parser_factory;
    using gnssxx::rinex::rinex_parser;
    using gnssxx::rinex::rinex_file_version;
    using gnssxx::rinex::rinex_file_type;
    using gnssxx::rinex::NAVMSG;

    rinex_file_version ver = rinex_file_version(2, 0);
    rinex_file_type type = gnssxx::rinex::NAVMSG;
    rinex_parser_factory::parser_ptr ptr = rinex_parser_factory::instance()
        ->get_parser(ver, type);
    ASSERT_EQ(ptr, nullptr);
}

/**
 * physical parsing context.
 */
class rinex_parse_context {
    public:
        rinex_parse_context(std::istream &in)
            : _M_in(in)
            , _M_lineno(0)
            , _M_section_type(RINEX_HEADER)
        {
        }

        enum section_type {
            RINEX_HEADER,
            RINEX_BODY,
        };

        int get_lineno() const {
            return _M_lineno;
        }
        void set_lineno(int value) {
            _M_lineno = value;
        }

        bool is_header() const {
            return _M_section_type == RINEX_HEADER;
        }

        section_type get_section_type() const {
            return _M_section_type;
        }

        void set_section_type(section_type value) {
            _M_section_type = value;
        }

        bool next_line(std::string &line,
                bool padding = false) {
            if (!_M_in)
                return false;
            std::getline(_M_in, line, '\n');
            if (padding) {
                std::vector<char> buffer(80 + 1);
                std::fill(buffer.begin(), buffer.end(), ' ');
                buffer[buffer.size() - 1] = 0;
                line.copy(&buffer[0], buffer.size() - 1, 0);
                line = &buffer[0];
            }
            ++_M_lineno;
            return !!_M_in;
        }
    protected:
    private:
        std::istream &_M_in;
        int _M_lineno;
        section_type _M_section_type;
};

#define ENUM_OS_BEGIN(type) \
    std::ostream& operator<<(std::ostream& os, type const &value) { \
        char const *p = "UNKNOWN"; \
        switch (value) {
#define ENUM_OS_ITEM(name) \
            case name: p = #name; break;
#define ENUM_OS_END() \
            default: break; \
        } \
       return os << p << "(" << static_cast<int>(value) << ")"; \
    }

ENUM_OS_BEGIN(rinex_parse_context::section_type)
ENUM_OS_ITEM(rinex_parse_context::RINEX_HEADER)
ENUM_OS_ITEM(rinex_parse_context::RINEX_BODY)
ENUM_OS_END()

TEST(rinex_test, test_read_local_rinex_file) {
    namespace fs = std::filesystem;
    std::cout << "stdout.fill() = '" << std::cout.fill() << "'" << std::endl;
    std::cout << "stdout.width() = " << std::cout.width() << std::endl;
    fs::path current_path = fs::current_path();
    current_path /= "..";
    current_path /= "..";
    current_path /= "tests";
    current_path /= "data";
    current_path /= "zimm0590.24n";
    std::string filename = current_path.string();
    std::cout << "filename = " << filename << std::endl;
    if (!fs::exists(filename))
        GTEST_SKIP();
    std::string line;
    // windows \r\n
    // linux   \n
    // mac     \r
    std::ifstream infile(
            filename.c_str(),
            std::ios_base::binary | std::ios_base::in);
    if (!infile)
        throw std::runtime_error("failed to open file " + filename);
    std::string formatted_line;
    rinex_parse_context ctx(infile);
    for ( ; ctx.next_line(formatted_line, true); ) {
        if (formatted_line.substr(60) == "END OF HEADER") {
        }
        std::cout
            << std::setw(4) << ctx.get_lineno()
            << " " << ctx.get_section_type()
            << formatted_line
            << std::endl;
    }
}

