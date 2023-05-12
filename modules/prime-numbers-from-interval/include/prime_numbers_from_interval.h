// Copyright 2023 Ivlev Alexander

#pragma once

#include <iostream>
#include <random>
#include <vector>


int gcd(int a, int b);
unsigned int ModMul(unsigned int a, unsigned int b, unsigned int M);
unsigned int ModExp(unsigned int x, unsigned int n, unsigned int M);

bool Miller_Rabin_primality_test(unsigned int N);
std::vector<unsigned int> primality_test_interval(unsigned int a,
    unsigned int b, unsigned int flag = 0);
