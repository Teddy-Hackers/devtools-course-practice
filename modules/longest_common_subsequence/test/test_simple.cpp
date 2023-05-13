// Copyright 2023 Yurin Evgeny

#include <gtest/gtest.h>

#include "include/longest_common_subsequence.h"

TEST(Check_lcs, Same_sequence) {
    std::vector<int> initialFirst{1, 2, 3, 6};
    std::vector<int> initialSecond{1, 2, 3, 6};
    std::vector<int> expectedResult{1, 2, 3, 6};

    std::vector<int> result = get_longest_common_subsequence(initialFirst,
                                                             initialSecond);

    ASSERT_EQ(expectedResult, result);
}

TEST(Check_lcs, Default_sequence) {
    std::vector<int> initialFirst{9, 8, 7, 6, 5, 4, 3};
    std::vector<int> initialSecond{9, 8, 7, 3};
    std::vector<int> expectedResult{9, 8, 7, 3};

    std::vector<int> result = get_longest_common_subsequence(initialFirst,
                                                             initialSecond);

    ASSERT_EQ(expectedResult, result);
}

TEST(Check_lcs, No_common_subsequence) {
    std::vector<int> initialFirst{1, 2, 3};
    std::vector<int> initialSecond{4, 5, 6};
    std::vector<int> expectedResult{};

    std::vector<int> result = get_longest_common_subsequence(initialFirst,
                                                             initialSecond);

    ASSERT_EQ(expectedResult, result);
}
