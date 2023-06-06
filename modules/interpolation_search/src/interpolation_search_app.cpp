// Copyright 2023 Nikolaev Alexander

#include "../include/interpolation_search_app.h"

void InterpolationSearchApp::help() {
    message.append("This is application for interpolation search");
}

std::string calc(std::vector<int> vec) {
    std::string res;
    interpolationSearch interpolationSearch(vec);
}

std::string InterpolationSearchApp::operator() (int argc, const char** argv) {
    if (argc <= 0) {
        help();
    }

    return "";
}