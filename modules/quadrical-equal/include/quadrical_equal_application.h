// Copyright 2023 Ermolaev Danila

#include <string>

class Quad_Application {
 public:
    Quad_Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

