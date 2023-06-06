//  Copyright 2023 Gosteeva Ekaterina

#include <gtest/gtest.h>
#include <cmath>
#include "include/Function_Eyler.h"
#include "include/Function_Eyler_Application.h"

TEST(Function_Eyler_App, Defult_App) {
    EXPECT_NO_THROW(Application application);
}

TEST(Function_Eyler_App, No_Throw_Wiht_Zero_argc) {
    Application application;
    int argc = 0;
    const char* argv[2] = { "1", "10" };
    EXPECT_NO_THROW(application(argc, argv));
}

TEST(Function_Eyler_App, Print_Help) {
    Application application;
    EXPECT_NO_THROW(application.help());
}
