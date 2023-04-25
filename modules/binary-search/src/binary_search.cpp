// Copyright 2023 Selivankin Sergey

#include "include/binary_search.h"

bool BinarySearch::checkSort(const std::vector<int> &_numbers) {
    for (int i = 0; i < static_cast<int>(_numbers.size() - 1); ++i) {
        if (_numbers[i] > _numbers[i + 1]) return false;
    }
    return true;
}

BinarySearch::BinarySearch(const std::vector<int> &_numbers) {
    this->setNumbers(_numbers);
}

void BinarySearch::setNumbers(const std::vector<int> &_numbers) {
    checkSort(_numbers) ?
    numbers = _numbers :
    throw std::invalid_argument("unsorted vector");
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
