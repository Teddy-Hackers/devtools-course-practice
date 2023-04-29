// Copyright 2023 Ustinov Alexandr

#include <gtest/gtest.h>

#include <utility>

#include "include/longest_inc_subseq.h"

TEST(Ustinov_LongestIncreasingSubsequenceTest, Sorted) {
    std::vector<int> source_array{1, 2, 3, 4, 5};

    std::vector<int> actual_array = 
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(source_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, Descending) {
    std::vector<int> source_array{5, 4, 3, 2, 1};
    std::vector<int> expected_array{1};

    std::vector<int> actual_array = 
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, TwoSortedSegments) {
    std::vector<int> source_array{4, 5, 6, 1, 2, 3};
    std::vector<int> expected_array{1, 2, 3};

    std::vector<int> actual_array = 
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, TwoAlternatingSortedParts1) {
    std::vector<int> source_array{4, 1, 5, 2, 6, 3};
    std::vector<int> expected_array{1, 2, 3};

    std::vector<int> actual_array = 
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, TwoAlternatingSortedParts2) {
    std::vector<int> source_array{1, 4, 2, 5, 3, 6};
    std::vector<int> expected_array{1, 2, 3, 6};

    std::vector<int> actual_array = 
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, RepeatingElements1) {
    std::vector<int> source_array{1, 1, 2, 2};
    std::vector<int> expected_array{1, 2};

    std::vector<int> actual_array = 
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, RepeatingElements2) {
    std::vector<int> source_array{1, 3, 1, 5, 5, 1};
    std::vector<int> expected_array{1, 3, 5};

    std::vector<int> actual_array = 
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}