// Copyright 2023 Lapin Dmitriy

#include <string>

class BaseCalculator {
 public:
    BaseCalculator();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string num1;
        int base1;
        std::string num2;
        int base2;
        char operation;
    } Arguments;

};
