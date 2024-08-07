#include <cstdlib>

#include <iomanip>
#include <istream>
#include <fstream>
#include <string>
#include <memory>
#include <iterator>

#include <gtest/gtest.h>

#include "misc/istream_line_iterator.hh"
#include "rinex/rinex_field.hh"
#include "rinex/rinex_integer_field.hh"
#include "rinex/rinex_real_field.hh"
#include "rinex/rinex_skip_field.hh"
#include "rinex/rinex_string_field.hh"
#include "rinex/rinex_compound_field.hh"
#include "rinex/rinex_compound_field_builder.hh"

namespace {

template <typename T>
void formatted(std::string const &fmt, T &value) {
}

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

TEST(arch_test, rinex_field) {
    using gnssxx::rinex::rinex_field;
    using gnssxx::rinex::rinex_real_field;
    using gnssxx::rinex::rinex_integer_field;
    using gnssxx::rinex::rinex_skip_field;
    using gnssxx::rinex::rinex_string_field;
    using gnssxx::rinex::rinex_compound_field;
    using gnssxx::rinex::rinex_compound_field_builder;

    std::string s = "20240727 2.11e+00  GPS";
    // std::string s = "20240727";

    rinex_compound_field cf = rinex_compound_field_builder()
        .I(4).I(2).I(2)
        .X(1).F(8, 2, "E")
        .X(1).A(4)
        .build();

    std::istringstream iss(s);
    iss >> cf;
    std::cout << s << std::endl;
    std::cout << cf << std::endl;
    /// F, I, A, X
    /// fieldf
    /// fieldi
    /// fielda
    /// fieldx
    ASSERT_EQ(std::dynamic_pointer_cast<rinex_integer_field>(cf[0])->value(), 2024);
    ASSERT_EQ(std::dynamic_pointer_cast<rinex_integer_field>(cf[1])->value(), 7);
    ASSERT_EQ(std::dynamic_pointer_cast<rinex_integer_field>(cf[2])->value(), 27);
    ASSERT_EQ(std::dynamic_pointer_cast<rinex_real_field>(cf[4])->value(), 2.11);
    ASSERT_EQ(std::dynamic_pointer_cast<rinex_string_field>(cf[6])->value(), " GPS");
}

TEST(arch_test, istream_ops) {
    std::istringstream iss;
    iss.str("    1.2   3.14159265398 ABC");
    double d;
    iss >> d;
    std::cout << d << std::endl;
    iss >> d;
    std::cout << d << std::endl;
    std::string s;
    iss >> s;
    std::cout << s << std::endl;
}
