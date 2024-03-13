#include <cstdlib>
#include <cstdio>
#include <ctime>

#include <map>
#include <iomanip>
#include <sstream>
#include <ostream>
#include <iostream>

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
