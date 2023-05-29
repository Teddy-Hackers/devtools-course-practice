// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

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

TEST(BigIntTest, SubtractionTest) {
    BigInt a("100000000000000000000");
    BigInt b("1");
    BigInt c("99999999999999999999");
    EXPECT_EQ(a - b, c);
}

TEST(BigIntTest, MultiplicationTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("199999999999999999998");
    EXPECT_EQ(a * b, c);
}

TEST(BigIntTest, DivisionTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("50000000000000000000");
    EXPECT_EQ(a / b, c);
}

TEST(BigIntTest, ModulusTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("1");
    EXPECT_EQ(a % b, c);
}
