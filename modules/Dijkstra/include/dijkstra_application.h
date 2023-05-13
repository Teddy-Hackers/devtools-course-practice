// Copyright 2023 Bulgakov Daniil

#pragma once

#include <string>

/**
 * @brief Application class for dijkstra algorithm.
 * @author Daniil Bulgakov
 */
class DijkstraApplication {
 public:
    DijkstraApplication();

    /**
     * @brief Functor override
     * @param[in] argc Number of command line arguments
     * @param[in] argv Command line arguments
     * @return Output expression
     */
    std::string operator()(int argc, const char** argv);

 private:
};
