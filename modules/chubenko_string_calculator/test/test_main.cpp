// Copyright 2023 CHUBENKO ANDREY

#include <gtest/gtest.h>

int Calc_main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
