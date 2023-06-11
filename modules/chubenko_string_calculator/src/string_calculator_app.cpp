// Copyright 2023 CHUBENKO ANDREY

#include <string>
#include <stdexcept>

#include "../include/string_calculator.h"
#include "../include/string_calculator_app.h"

StringCalculatorApp::StringCalculatorApp() {}

std::string StringCalculatorApp::operator() (int argc, const char** argv) {
    if (argc != 2) {
        return this->argument_error();
    }

    std::string arg = std::string(argv[1]);
    if (arg == "--help" || arg == "-h") {
        return this->help();
    }

    try {
        CalcStringCalculator sc;
        sc.set_Calc_infix(arg);
        double result = sc.CalcCalculate();
        return std::to_string(result);
    } catch (std::invalid_argument& e) {
        return this->calc_error(e);
    }
}

std::string StringCalculatorApp::help() {
    std::string help = std::string("")
        +  "Glad to see you in the string calculator app!\n"
        +  "Please, provide mathematical expression to be calculated\n"
        +  "Generally you can type something like (111+4)/5*6^2 \n"
        +  "Supported operations are: '+' '-' '/' '*' '^'";
    return help;
}

std::string StringCalculatorApp::argument_error() {
    std::string error = std::string("")
    + "Invalid argument amount, try --help or -h command";
    return error;
}

std::string StringCalculatorApp::calc_error(const std::invalid_argument& e) {
    std::string error = std::string("")
    + "Calculation error!\n"
    + e.what();
    return error;
}
