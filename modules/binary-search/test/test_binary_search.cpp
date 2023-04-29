// Copyright 2023 Selivankin Sergey

#include <gtest/gtest.h>
#include "include/binary_search.h"

TEST(BinarySearch, can_find_existing_number) {
    // Arrange
    std::vector<int> a = {1, 2, 3, 4, 5, 6};

    // Act & Assert
    for (size_t i = 0; i < a.size(); ++i) {
        ASSERT_EQ(i, BinarySearch::find(a, a[i]));
    }
}

TEST(BinarySearch, search_for_non_existent_return_negative_number) {
    // Arrange
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    std::size_t expected = -1;

    // Act
    std::size_t result = BinarySearch::find(a, 7);

    // Assert
    EXPECT_EQ(expected, result);
}

TEST(BinarySearch, search_in_one_size_array) {
    // Arrange
    std::vector<int> a = {1};
    std::size_t expected = 0;

    // Act
    std::size_t result = BinarySearch::find(a, 1);

    // Assert
    EXPECT_EQ(expected, result);
}
