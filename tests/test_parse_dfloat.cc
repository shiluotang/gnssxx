#include <algorithm>

#include <gtest/gtest.h>

namespace {

std::string replace_all(
        std::string &s,
        std::string const &orig,
        std::string const &replacement) {
    typedef std::string::size_type size_type;
    for (size_type pos = 0, off = 0;
            (pos = s.find(orig, off)) != std::string::npos;
            off = pos + replacement.length()) {
        s.replace(pos, orig.length(), replacement);
    }
    return s;
}

std::string replace_all(
        std::string const &s,
        std::string const &orig,
        std::string const &replacement) {
    std::string r = s;
    replace_all(r, orig, replacement);
    return r;
}

}

TEST(dfloat_parse, test_fixed_width) {
    double value = 0;
    int used = 0;
    int n = 0;
    std::string s = "-.5898D+06-.5897D+07";
    s = replace_all(s, "D", "E");
    n = std::sscanf(&s[0], "%10lf%n", &value, &used);
    ASSERT_EQ(n, 1);
    ASSERT_EQ(value, -.5898e+06);
    ASSERT_EQ(used, 10);
}

TEST(dfloat_parse, replace_check) {
    std::string s = "hello";
    ASSERT_EQ(s, "hello");
    s.replace(s.begin(), s.begin() + 1, "H");
    ASSERT_EQ(s, "Hello");
    s.replace(s.begin(), s.begin() + 1, "HH");
    ASSERT_EQ(s, "HHello");
}

TEST(dfloat_parse, replace_all_check) {
    std::string s = "hello";
    ASSERT_EQ(s, "hello");
    replace_all(s, "h", "H");
    ASSERT_EQ(s, "Hello");
    replace_all(s, "l", "H");
    ASSERT_EQ(s, "HeHHo");
}
