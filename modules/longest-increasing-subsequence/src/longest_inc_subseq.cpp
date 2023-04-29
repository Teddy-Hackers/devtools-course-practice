// Copyright 2023 Ustinov Alexandr

#include <cinttypes>
#include <algorithm>
#include <limits>
#include "include/longest_inc_subseq.h"

// returns the longest increasing subsequence of 'array' i.e.
// vector 'v' of size 's' s.t. v[i] = array[k_i],
// 0 <= k_0 < k_1 < ... < k_{s-2} < k_{s-1} < array.size(),
// v[0] < v[1] < ... < v[s-2] < v[s-1]
std::vector<int> longestIncreasingSubsequence(const std::vector<int> &array) {
    size_t longest_inc_subseq_len = 0;
    // last element in longest increasing subsequence
    size_t last_element_idx = 0;
    // index of previous element in increasing subsequence
    // which ends in element 'array[i]'
    std::vector<int64_t> prev_element_idx(array.size());
    // smallest last element in increasing subsequence of length 'i'
    std::vector<int> last_element(array.size() + 1);

    // initialize 'last_number[]':
    last_element[0] = std::numeric_limits<int>::min();
    for (size_t i = 1; i <= array.size(); ++i)
        last_element[i] = std::numeric_limits<int>::max();

    // dynamic programming to fill 'prev_element_idx[]' and 'last_element[]'
    for (size_t i = 0; i < array.size(); ++i) {
        // find smallest index 'j' s.t. last_element[j] >= array[i]
        size_t j = std::lower_bound(last_element.begin(), last_element.end(),
                                    array[i]) - last_element.begin();
        // if 'array[i]' is an element of increasing subsequence
        // then 'last_element[j-1]' is the previous element in the subsequence
        prev_element_idx[i] = last_element[j-1];

        // update smallest last element in subsequence of length 'j'
        last_element[j] = array[i];

        // update maximal length of increasing subsequence
        if (j > longest_inc_subseq_len) {
            longest_inc_subseq_len = j;
            last_element_idx = i;
        }
    }

    // vector which contains longest increasing subsequence
    std::vector<int> longest_inc_subseq(longest_inc_subseq_len);
    // current index in 'prev_element_idx[]' as we go
    // from last element to first in longest increasing subsequence
    size_t current_idx = last_element_idx;

    for (size_t i = 0; i < longest_inc_subseq_len; ++i) {
        longest_inc_subseq[longest_inc_subseq_len - 1 - i] = array[current_idx];
        current_idx = prev_element_idx[current_idx];
    }

    return longest_inc_subseq;
}
