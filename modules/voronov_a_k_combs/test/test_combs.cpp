// Copyright 2023 Voronov Alexandr

#include <gtest/gtest.h>

#include <vector>

#include "include/combs.h"

TEST(combs_in_array, test_0) {
    int tot;
    combs cab;
    tot = cab.getter();
    ASSERT_EQ(2, tot);
}

TEST(combs_in_array, test_1) {
    int tot;
    combs cab(6, 4);
    tot = cab.getter();
    ASSERT_EQ(15, tot);
}

TEST(combs_in_array, test_2) {
    combs cab(7, 14);
    EXPECT_ANY_THROW(cab.getter());
}

TEST(combs_in_array, test_3) {
    int tot;
    combs cab(5, 4);
    tot = cab.getter();
    ASSERT_EQ(5, tot);
}

TEST(combs_in_array, test_4) {
    int res;
    combs cab(15, 15);
    res = cab.getter();
    ASSERT_EQ(1, res);
}
