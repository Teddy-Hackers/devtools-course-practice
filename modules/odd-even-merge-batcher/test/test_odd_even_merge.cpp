// Copyright 2023 Nikolaev Alexander

#include <gtest/gtest.h>
#include "include/odd_even_merge.h"

bool checkSortArray(const std::vector<int>& array) {
    return std::is_sorted(array.begin(), array.end());
}

TEST(OddEvenMerge, can_sort_array) {
    // Arrange
    std::vector<int> array = {6, 5, 4, 3, 2, 1};

    // Act
    OddEvenMergeBatcherSort(&array);

    // Assert
    ASSERT_TRUE(checkSortArray(array));
}

TEST(OddEvenMerge, can_sort_random_array) {
    // Arrange
    std::vector<int> array = getRandomArray(20);

    // Act
    OddEvenMergeBatcherSort(&array);

    // Assert
    ASSERT_TRUE(checkSortArray(array));
}

TEST(OddEvenMerge, can_sort_an_array_of_negative_numbers) {
    // Arrange
    std::vector<int> array = {-1, -2, -3, -4, -5, -6};

    // Act
    OddEvenMergeBatcherSort(&array);

    // Assert
    ASSERT_TRUE(checkSortArray(array));
}
