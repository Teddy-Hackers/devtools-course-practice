//  Copyright 2023 Rezchikov Dmitrii

#include <gtest/gtest.h>
#include "../include/long_num.h"


TEST(LongNumTest, fic_test) {
    ASSERT_EQ(true, true);
}

TEST(LongNumTest, Can_Add) {
    LongNumber n1("123");
    LongNumber n2("123");
    LongNumber n3 = n1 + n2;

    ASSERT_EQ(n3, LongNumber("246"));
}

TEST(LongNumTest, Can_Subtract) {
    LongNumber n1("123");
    LongNumber n2("122");
    LongNumber n3 = n1 - n2;

    // n3.print();

    ASSERT_EQ(n3, LongNumber("1"));


}
