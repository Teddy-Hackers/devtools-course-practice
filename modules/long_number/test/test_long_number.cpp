// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/longNumber.h"

TEST(LongNumberTest, ArgCheckingValid) {
  longNumber longN;
  const char* args1[] = {"12345", "+", "23456" }; 
  EXPECT_TRUE(longN.argChecking(4, args1));
}

TEST(LongNumberTest, ArgCheckingInvalid) {
  longNumber longN;
  const char* args2[] = {"123", "45", "678" }; 
  EXPECT_FALSE(longN.argChecking(4, args2));
}

TEST(LongNumberTest, CompareOrCountDifference) {
  longNumber longN;
  const char* args1[] = {"12345", "-", "23456" }; 
  EXPECT_EQ(longN.compareOrCount(), "-11111"); 
}

TEST(LongNumberTest, CompareOrCountModulo) {
  longNumber longN;
  const char* args2[] = {"23456", "%", "678" }; 
  EXPECT_EQ(longN.compareOrCount(), "394"); 
}

TEST(LongNumberTest, CompareOrCountDivision) {
  longNumber longN;
  const char* args3[] = {"12345", "/", "23456" }; 
  EXPECT_EQ(longN.compareOrCount(), "0"); 
}