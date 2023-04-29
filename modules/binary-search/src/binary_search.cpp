// Copyright 2023 Selivankin Sergey

#include "include/binary_search.h"

std::size_t BinarySearch::find(const std::vector<int> &numbers, int target) {
    std::size_t left = 0;
    std::size_t right = numbers.size() - 1;

    while (left <= right) {
        std::size_t mid = (left + right) / 2;
        if (numbers[mid] == target) {
            return mid;
        }
        if (numbers[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
