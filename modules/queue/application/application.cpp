// Copyright 2023 Prokofev Denis

#include <stdio.h>
#include <iostream>
#include "include/queue_app.h"

int main(int argc, const char** argv) {
    QueueApp<int> queueapp;
    std::string output = queueapp(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
