// Copyright 2023 Ustinov Alexandr

#include <gtest/gtest.h>

#include <utility>

#include "include/longest_inc_subseq.h"

TEST(Ustinov_LongestIncreasingSubsequenceTest, Empty) {
    std::vector<int> source_array{};
    std::vector<int> expected_array{};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, Sorted1) {
    std::vector<int> source_array{1, 2, 3, 4, 5};
    std::vector<int> expected_array{1, 2, 3, 4, 5};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, Sorted2) {
    std::vector<int> source_array{2, 3, 5, 8, 13};

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

TEST(Ustinov_LongestIncreasingSubsequenceTest, RepeatingElements3) {
    std::vector<int> source_array{7, 7, 7, 7, 7, 7};
    std::vector<int> expected_array{7};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

// "Random" = "Generated by external RNG service"
TEST(Ustinov_LongestIncreasingSubsequenceTest, Random1) {
    std::vector<int> source_array{9, 2, 3, 9, 10, 10, 2, 3};
    std::vector<int> expected_array{2, 3, 9, 10};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, Random2) {
    std::vector<int> source_array{6, 7, 10, 4, 4, 4, 2, 1};
    std::vector<int> expected_array{6, 7, 10};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, Random3) {
    std::vector<int> source_array{1, 7, 7, 7, 8, 6, 5, 6};
    std::vector<int> expected_array{1, 5, 6};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, Random4) {
    std::vector<int> source_array{1, 3, 4, 3, 5, 7, 7, 8};
    std::vector<int> expected_array{1, 3, 4, 5, 7, 8};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, Random5) {
    std::vector<int> source_array{1, 4, 9, 3, 8, 10, 7, 8};
    std::vector<int> expected_array{1, 3, 7, 8};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, WithMinimalValue1) {
    constexpr int int_min = std::numeric_limits<int>::min();
    std::vector<int> source_array{int_min, 1};
    std::vector<int> expected_array{int_min, 1};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, WithMinimalValue2) {
    constexpr int int_min = std::numeric_limits<int>::min();
    std::vector<int> source_array{1, int_min};
    std::vector<int> expected_array{int_min};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, WithMinimalValue3) {
    constexpr int int_min = std::numeric_limits<int>::min();
    std::vector<int> source_array{1, 3, int_min, 1, 3};
    std::vector<int> expected_array{int_min, 1, 3};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, WithMaximalValue1) {
    constexpr int int_max = std::numeric_limits<int>::max();
    std::vector<int> source_array{int_max, 1};
    std::vector<int> expected_array{int_max};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, WithMaximalValue2) {
    constexpr int int_max = std::numeric_limits<int>::max();
    std::vector<int> source_array{1, int_max};
    std::vector<int> expected_array{1, int_max};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}

TEST(Ustinov_LongestIncreasingSubsequenceTest, WithMaximalValue3) {
    constexpr int int_max = std::numeric_limits<int>::max();
    std::vector<int> source_array{1, 3, int_max, 1, 3};
    std::vector<int> expected_array{1, 3, int_max};

    std::vector<int> actual_array =
        longestIncreasingSubsequence(source_array);

    EXPECT_EQ(expected_array, actual_array);
}
