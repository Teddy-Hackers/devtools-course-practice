// Copyright 2023 Ustinov Alexandr

#include <gtest/gtest.h>

#include <utility>

#include "include/longest_inc_subseq.h"

TEST(Ustinov_LongestIncreasingSubsequenceTest, CorrectForSortedArray) {
    std::vector<int> sorted_array{1, 2, 3, 4, 5};

    std::vector<int> actual_array = longestIncreasingSubsequence(sorted_array);

    EXPECT_EQ(sorted_array, actual_array);
}
