// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

TEST(BigIntConstructorTest, fromString) {
  BigInt n("12345678901234567890");
  EXPECT_EQ(n.toString(), "12345678901234567890");
}

TEST(BigIntConstructorTest, fromInt) {
  BigInt n(1234567890);
  EXPECT_EQ(n.toString(), "1234567890");
}

TEST(BigIntConstructorTest, copyConstructor) {
  BigInt n1("9876543210");
  BigInt n2(n1);
  EXPECT_EQ(n2, n1);
}

TEST(BigIntConstructorTest, assignmentOperator) {
  BigInt n1("1234567890");
  BigInt n2 = n1;
  EXPECT_EQ(n2, n1);
}

TEST(BigIntOperatorTest, addition) {
  BigInt n1("1234567890");
  BigInt n2("9876543210");
  BigInt result("11111111100");
  EXPECT_EQ(n1 + n2, result);
}

TEST(BigIntOperatorTest, subtraction) {
  BigInt n1("1234567890");
  BigInt n2("9876543210");
  BigInt result("-8641975320");
  EXPECT_EQ(n1 - n2, result);
}

TEST(BigIntOperatorTest, multiplication) {
  BigInt n1("1234567890");
  BigInt n2("9876543210");
  BigInt result("12193263113765544300");
  EXPECT_EQ(n1 * n2, result);
}

TEST(BigIntOperatorTest, division) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  BigInt result("1");  
  EXPECT_EQ(n1 / n2, result);
}

TEST(BigIntOperatorTest, modulo) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  BigInt result("246913619");  
  EXPECT_EQ(n1 % n2, result);
}

TEST(BigIntOperatorTest, greaterThan) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  EXPECT_TRUE(n1 > n2);
  EXPECT_FALSE(n2 > n1);
}

TEST(BigIntOperatorTest, lessThan) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  EXPECT_FALSE(n1 < n2);
  EXPECT_TRUE(n2 < n1);
}

TEST(BigIntOperatorTest, greaterThanOrEqual) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  BigInt n3("1234567890");
  EXPECT_TRUE(n1 >= n2);
  EXPECT_TRUE(n1 >= n3);
  EXPECT_FALSE(n2 >= n1);
}

TEST(BigIntOperatorTest, lessThanOrEqual) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  BigInt n3("1234567890");
  EXPECT_FALSE(n1 <= n2);
  EXPECT_TRUE(n1 <= n3);
  EXPECT_TRUE(n2 <= n1);
}

TEST(BigIntOperatorTest, equality) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  BigInt n3("1234567890");
  EXPECT_FALSE(n1 == n2);
  EXPECT_TRUE(n1 == n3);
}

TEST(BigIntOperatorTest, inequality) {
  BigInt n1("1234567890");
  BigInt n2("987654321");
  BigInt n3("1234567890");
  EXPECT_TRUE(n1 != n2);
  EXPECT_FALSE(n1 != n3);
}