#include <gtest/gtest.h>
#include <rkc/string_literal.hpp>

template <rkc::string_literal_t str>
std::string std_string_from_template()
{
    return {str};
}

TEST(StringLiteralTest, std_string_cmp)
{
    EXPECT_EQ("std string", std_string_from_template<"std string">());
}

TEST(StringLiteralTest, char_arr_cmp)
{
    constexpr rkc::string_literal_t str = "char";
    EXPECT_STREQ(str, "char");
}

TEST(StringLiteralTest, copying_behavior)
{
    constexpr rkc::string_literal_t str = "Copy";
    rkc::string_literal_t strCopy = str;
    EXPECT_STREQ(strCopy, "Copy");
}