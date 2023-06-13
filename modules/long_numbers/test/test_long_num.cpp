//  Copyright 2023 Rezchikov Dmitrii

#include <gtest/gtest.h>
#include "../include/long_num.h"


TEST(LongNumTest, fic_test) {
    ASSERT_EQ(true, true);
}

TEST(LongNumTest, Can_Add) {
    LongNumber n1("123");
    LongNumber n2("123");
    LongNumber expected = LongNumber("246");
    
    LongNumber n3 = n1 + n2;
    
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Can_Subtract) {
    LongNumber n1("123");
    LongNumber n2("122");
    LongNumber expected = LongNumber("1");
    
    LongNumber n3 = n1 - n2;

    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Subtract_from_lesser) {
    LongNumber n1("121");
    LongNumber n2("122");
    LongNumber expected = LongNumber("1");
    expected.changeSign();

    LongNumber n3 = n1 - n2;
    // std::cout << n3 << "\n";

    ASSERT_EQ(n3, expected);

}
