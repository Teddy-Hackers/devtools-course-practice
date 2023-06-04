// Copyright 2023 Voronov Alexandr

#include "include/combs.h"

#include <vector>

combs::combs() {
    std::vector<int> _tmp_v(1, 0);
    this->a = 1;
    this->b = 1;
    this->v = _tmp_v;
}

combs::combs(int _a, int _b) {
    std::vector<int> v(_b, 0);
    for (int i = 0; i < _b; i++) {
        v[i] = i + 1;
    }
    this->a = _a;
    this->b = _b;
    this->v = v1;
}

bool combs::setter() {
    for (int i = b - 1; i >= 0; i--) {
        if (v[i] < a - b + i + 1) {
            v[i]++;
            for (int j = i; j < b - 1; j++) {
                v[j + 1] = v[j] + 1;
            }
            return true;
        }
    }
    return false;
}

int combs::getter() {
    int total = 0;
    if (a >=b) {
        while (setter()) {
            total++;
        }
    } else {
        throw std::invalid_argument("a is less thea b");
    }
    total++;
    return total;
}

combs::~combs() {
    this->a = 0;
    this->b = 0;
    this->v.clear();
}
