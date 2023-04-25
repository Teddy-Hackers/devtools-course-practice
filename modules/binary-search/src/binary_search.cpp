// Copyright 2023 Selivankin Sergey

#include "include/binary_search.h"

void BinarySearch::sort() {
    std::sort(std::begin(this->numbers), std::end(this->numbers));
}

BinarySearch::BinarySearch(const std::vector<int> &numbers) {
    this->numbers = numbers;
    sort();
}

int BinarySearch::find(const int& target) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
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

int BinarySearch::findIn(const int& target, const std::vector<int>& _numbers) {
    this->numbers = std::vector<int>(_numbers);
    sort();
    return find(target);
}
