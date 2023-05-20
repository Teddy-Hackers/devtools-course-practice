#pragma once

class application_t
{
 public:
    application_t() = default;

    int run(int argc, char* argv[]);

    ~application_t() = default;
};