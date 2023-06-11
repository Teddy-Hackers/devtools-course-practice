// Copyright 2023 Prokofev Denis

#include <stdio.h>

#include "include/queue_app.h"

int main(int argc, const char** argv) {
    QueueApp<int> queueapp;
    printf("%s\n", queueapp(argc, argv).c_str());
    return 0;
}
