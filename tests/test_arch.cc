#include <cstdlib>
#include <cmath>

#include <iomanip>
#include <istream>
#include <fstream>
#include <string>
#include <memory>
#include <iterator>
#include <typeinfo>
#include <type_traits>

#include <gtest/gtest.h>

#include "misc/istream_line_iterator.hh"
#include "rinex/rinex_parser.hh"

namespace {

} // namespace

TEST(arch_test, lines_iterator) {
    using gnssxx::misc::istream_line_iterator;
    std::ifstream infile("../../tests/data/zimm0590.24n");
    if (!infile)
        GTEST_SKIP() << "file failed to be opened for read!";
    int lines = 0;
    for (istream_line_iterator it(&infile), e; it != e; ++it) {
        std::cout << *it << std::endl;
        ++lines;
    }
    ASSERT_EQ(1519, lines);
}

TEST(arch_test, rinex_parser) {
    gnssxx::rinex::rinex_parser parser;
    std::ifstream infile("../../tests/data/zimm0590.24n");
    if (!infile)
        GTEST_SKIP() << "file failed to be opened for read!";
    gnssxx::misc::istream_line_iterator it(&infile);
    gnssxx::rinex::rinex_metadata metadata;
    ASSERT_TRUE(parser.parse_metadata(*it++, metadata));
    ASSERT_EQ(gnssxx::rinex::rinex_file_version(2.11), metadata.get_version());
    ASSERT_EQ(gnssxx::rinex::NAVMSG, metadata.get_type());
    ASSERT_EQ(gnssxx::rinex::GPS, metadata.get_satsys());
}

