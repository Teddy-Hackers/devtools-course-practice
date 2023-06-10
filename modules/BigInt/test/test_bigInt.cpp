// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

TEST(BigIntTest, DefaultConstructorTest) {
    BigInt x;
    EXPECT_FALSE(x.is_negative);
    EXPECT_EQ(x.digits, "0");
}

TEST(BigIntTest, ConstructorTest) {
    int n = 12345;
    BigInt num(n);
    EXPECT_FALSE(num.is_negative);
    EXPECT_EQ(num.digits, "12345");

    int n = -54321;
    BigInt num(n);
    EXPECT_TRUE(num.is_negative);
    EXPECT_EQ(num.digits, "54321");
}

TEST(BigIntConstructor, LargePositiveNumber) {
    BigInt a("123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, false);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntConstructor, LargeNegativeNumber) {
    BigInt a("-123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, true);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntTest, AdditionTest) {
    BigInt a("99999999999999999999");
    BigInt b("1");
    BigInt c("100000000000000000000");
    EXPECT_EQ(a + b, c);
}

TEST(BigIntTest, MultiplicationTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("199999999999999999998");
    EXPECT_EQ(a * b, c);
}

TEST(BigIntTest, GreaterThanOperatorTestFirst) {
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

    EXPECT_FALSE(c > b);
}

TEST(BigIntTest, GreaterThanOperatorTestSecond) {
    BigInt a("123456789012345678901234567890");
    BigInt c("-123456789012345678901234567890");

    EXPECT_TRUE(a > c);
}

TEST(BigIntTest, GreaterThanOperatorTestThird) {
    BigInt a("123456789012345678901234567890");
    BigInt b("98765432109876543210987654321");

    EXPECT_TRUE(b > a);
}

TEST(BigIntTest, GreaterThanOperatorTest) {
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

    EXPECT_TRUE(b > c);
}

TEST(BigIntTest, GreaterThanOrEqualToOperatorTest) {
    BigInt a("1364763897649287634876836487");
    BigInt b("1364763897649287634876836487");
    BigInt c("-1364763897649287634876836487");

    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(a >= c);
    EXPECT_FALSE(c >= a);
    EXPECT_TRUE(b >= b);
}

TEST(BigIntTest, LessThanOperatorTestFirst) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_TRUE(b < a);
    EXPECT_FALSE(a < b);
}

TEST(BigIntTest, LessThanOperatorTestSecond) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_FALSE(a < b);
}

TEST(BigIntTest, LessThanOrEqualToOperatorTest) {
    BigInt a("-123456789012345678901234567890");
    BigInt b("123456789012345678901234567890");

    EXPECT_TRUE(a <= b);
}

TEST(BigIntTest, EqualityOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-123456789012345678901234567890");
    BigInt c("123456789012345678901234567890");

    EXPECT_TRUE(a == a);
    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == c);
}

TEST(BigIntTest, NotEqualityOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-123456789012345678901234567890");
    BigInt c("123456789012345678901234567890");

    EXPECT_FALSE(a != a);
    EXPECT_FALSE(a != c);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != c);
}

TEST(BigIntTest, AddAbsTest) {
    std::string a = "1000000000000000000000000000000";
    std::string b = "1234567891234567891234";
    std::string expected = "1000000001234567891234567891234";
    EXPECT_EQ(BigInt::add_abs(a, b), expected);
}

TEST(BigIntTest, SubtractAbsTest) {
    std::string a = "1000000000000000000000000000000";
    std::string b = "1234567891234567891234";
    std::string expected = "999999998765432108765432108766";
    EXPECT_EQ(BigInt::subtract_abs(a, b), expected);
}

TEST(BigIntTest, MultiplyIntTest) {
    std::string a = "1000000000000000000000";
    int b = 5;
    std::string expected = "5000000000000000000000";
    EXPECT_EQ(BigInt::multiply_int(a, b), expected);
}

TEST(BigIntTest, CompareAbsTest) {
    std::string a = "123456789";
    std::string b = "234567891";
    EXPECT_TRUE(BigInt::compare_abs(a, b));
}

TEST(BigIntTest, MultiplyTest) {
    std::string a = "111111111111111111111";
    std::string b = "123456789111112131415";
    std::string expected = "13717421012345792379430727023432098652065";
    EXPECT_EQ(BigInt::multiply(a, b), expected);
}

TEST(BigIntTest, DivideTest) {
    std::string a = "123456789";
    std::string b = "7";
    std::pair<std::string, std::string> result = BigInt::divide(a, b);
    EXPECT_EQ(result.first, "200000000");
    EXPECT_EQ(result.second, "723456789");

    a = "123456789";
    b = "7";
    result = BigInt::divide(a, b);
    EXPECT_EQ(result.first, "200000000");
    EXPECT_EQ(result.second, "723456789");
}

TEST(BigIntOperatorPlus, Addition) {
    EXPECT_EQ(BigInt("100"), BigInt("23") + BigInt("77"));
    EXPECT_EQ(BigInt("100"), BigInt("77") + BigInt("23"));
}
