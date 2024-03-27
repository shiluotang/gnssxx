#include <gtest/gtest.h>

TEST(DFloatParse, testNegative) {
    std::string s = "-.5898D+06-.5897D+07";
    double value;
    // std::string::size_type off = 0;
    // std::string::size_type pos = 0;
    // while (off != std::string::npos) {
    //     pos = s.find("D", off);
    //     if (pos == std::string::npos) {
    //         off = pos;
    //         continue;
    //     }
    //     s.replace(pos, 1, "E");
    //     off = pos + 1;
    // }
    int used = 0;
    int n = std::sscanf(&s[0], "%10lf%n", &value, &used);
    ASSERT_EQ(n, 1);
    std::cout << "value = " << value << std::endl;
    std::cout << "used = " << used << std::endl;
}

