// Copyright 2023 Ivlev Alexander

#include "include/prime_numbers_from_interval.h"

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

unsigned int ModMul(unsigned int a,
    unsigned int b, unsigned int M) {
        if (b == 0) {
            return 0;
        }

        unsigned int z = ModMul(a, b / 2, M);

        if (b % 2 == 0) {
            return ((2 * z) % M);
        } else {
            return ((a + ((2 * z) % M)) % M);
        }
}

unsigned int ModExp(unsigned int x,
    unsigned int n, unsigned int M) {
        if (n == 0) {
            return 1;
        }

        unsigned int z = ModExp(x, n / 2, M);

        if (n % 2 == 0) {
            return ModMul(z, z, M);
        } else {
            return ModMul(ModMul(z, z, M), x, M);
        }
}

bool Miller_Rabin_primality_test(unsigned int N) {
    if (N < 2) {
        return false;
    }

    unsigned int multiplier = 0;

    if (N % 2 == 0) {
        multiplier = 2;
    }

    if (N % 3 == 0) {
        multiplier = 3;
    }

    if (multiplier != 0 && multiplier != N) {
        return false;
    } else {
        return true;
    }

    std::mt19937 gen(N);
    std::uniform_int_distribution<unsigned int> uid(2, N - 1);

    while (multiplier == 0) {
        unsigned int X = 0;
        X = uid(gen);
        if (gcd(X, N) != 1) {
            multiplier = gcd(X, N);
            break;
        }

        unsigned int u = N - 1;
        unsigned int t = 0;

        while (u % 2 == 0) {
            u /= 2;
            t++;
        }

        unsigned int temp = u;

        for (unsigned int i = 0; i <= t; i++) {
            if (ModExp(X, u, N) == 1) {
                if (i == t) {
                    multiplier = N;
                    break;
                }

                if (i != 0) {
                    if (u != N-1 && ModExp(temp, u, N) != N-1 && N%temp == 0) {
                        multiplier = temp;
                    }

                    break;
                }
            }

            temp = u;
            u *= 2;
        }
    }

    if (multiplier != N) {
        return false;
    } else {
        return true;
    }
}

std::vector<unsigned int> primality_test_interval(size_t a,
    size_t b, size_t flag) {
        std::vector<unsigned int> prime;

        for (int i = a; i <= b; i++) {
            if (Miller_Rabin_primality_test(i)) {
                prime.push_back(i);
            }
        }

        if (flag) {
            for (int j = 0; j < prime.size(); j++) {
                std::cout << prime[j] << ' ';
            }
            std::cout << '\n';
        }

        return prime;
}
