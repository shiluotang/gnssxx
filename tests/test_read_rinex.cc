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

TEST(rinex_test, test_read_local_rinex_file) {
    namespace fs = std::filesystem;
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
    std::vector<char> buffer(80 + 1, 0);
    std::string formatted_line;
    for ( ; std::getline(infile, line, '\n'); ) {
        std::fill(buffer.begin(), buffer.end(), ' ');
        buffer[buffer.size() - 1] = 0;
        line.copy(&buffer[0], buffer.size() - 1, 0);
        formatted_line = &buffer[0];
        if (formatted_line.substr(60) == "END OF HEADER") {
        }
        std::cout << formatted_line << std::endl;
    }
}

