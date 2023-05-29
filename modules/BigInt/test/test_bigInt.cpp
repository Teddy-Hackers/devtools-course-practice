// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

TEST(BigIntConstructor, EmptyConstructor) {
    BigInt big_integer;

    ASSERT_EQ(big_integer.IsNegative(), false);
    ASSERT_EQ(big_integer.ToString(), "0");
}

TEST(BigIntConstructor, StringConstructorPositive) {
    std::string input = "123456789";

    BigInt big_integer(input);

    ASSERT_EQ(big_integer.IsNegative(), false);
    ASSERT_EQ(big_integer.ToString(), input);
}

TEST(BigIntConstructor, StringConstructorNegative) {
    std::string input = "-987654321";

    BigInt big_integer(input);

    ASSERT_EQ(big_integer.IsNegative(), true);
    ASSERT_EQ(big_integer.ToString(), "987654321");
}

TEST(BigIntConstructor, StringConstructorLeadingZeros) {
    std::string input = "0000123456789000000";

    BigInt big_integer(input);

    ASSERT_EQ(big_integer.IsNegative(), false);
    ASSERT_EQ(big_integer.ToString(), "123456789000000");
}

TEST(BigIntConstructor, IntConstructorPositive) {
    int input = 123456789;

    BigInt big_integer(input);

    ASSERT_EQ(big_integer.IsNegative(), false);
    ASSERT_EQ(big_integer.ToString(), "123456789");
}

TEST(BigIntConstructor, IntConstructorNegative) {
    int input = -987654321;

    BigInt big_integer(input);

    ASSERT_EQ(big_integer.IsNegative(), true);
    ASSERT_EQ(big_integer.ToString(), "987654321");
}

TEST(BigIntConstructor, IntConstructorZero) {
    int input = 0;

    BigInt big_integer(input);

    ASSERT_EQ(big_integer.IsNegative(), false);
    ASSERT_EQ(big_integer.ToString(), "0");
}

TEST(BigIntConstructor, CopyConstructor) {
    BigInt original(123456789);

    BigInt copied(original);

    ASSERT_EQ(copied.IsNegative(), false);
    ASSERT_EQ(copied.ToString(), "123456789");
    ASSERT_NE(&copied, &original);
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

TEST(BigIntOperator, AssignmentOperator) {
    BigInt original(123456789);
    BigInt assigned = original;

    ASSERT_EQ(assigned.IsNegative(), false);
    ASSERT_EQ(assigned.ToString(), "123456789");
    ASSERT_NE(&assigned, &original);

    BigInt other(987654321);
    assigned = other;

    ASSERT_EQ(assigned.IsNegative(), false);
    ASSERT_EQ(assigned.ToString(), "987654321");
    ASSERT_NE(&assigned, &other);
    ASSERT_EQ(original.ToString(), "123456789");
}

TEST(BigIntTest, AdditionTest) {
    BigInt a("99999999999999999999");
    BigInt b("1");
    BigInt c("100000000000000000000");
    EXPECT_EQ(a + b, c);
}

TEST(BigIntTest, Subtraction) {
    BigInt a("12345");
    BigInt b("6789");

    BigInt result = a - b;

    ASSERT_EQ(result.toString(), "5556");
}

TEST(BigIntTest, Division) {
    BigInt a("12345678901234567890");
    BigInt b("12345678901234567890");

    BigInt result = a / b;

    ASSERT_EQ(result.toString(), "1");
}

TEST(BigIntTest, Modulo) {
    BigInt a("12345678901234567890");
    BigInt b("12345678901234567890");

    BigInt result = a % b;

    ASSERT_EQ(result.toString(), "0");
}

TEST(BigIntTest, MultiplicationTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("199999999999999999998");
    EXPECT_EQ(a * b, c);
}

TEST(BigIntTest, GreaterThanOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

    EXPECT_FALSE(c > b);
    EXPECT_TRUE(a > c);
    EXPECT_TRUE(b > a);
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

TEST(BigIntTest, LessThanOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_TRUE(b < a);
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
