// Copyright 2023 Prokofev Denis

#include "include/queue_app.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

template <typename T>
void QueueApp<T>::help() {
    message.append("This is application for create Queue.\n")
    .append("Add data with push\n")
    .append("Read data with pop\n")
    .append("All elements must be integer!");
}

template <typename T>
int QueueApp<T>::findOperation(int argc, const char** argv) {
    std::vector < std::string> dop;
    std::vector < std::string>::iterator it;
    for (int i = 1; i <= argc - 1; i++)
        dop.push_back(std::string(argv[i]));
    if (std::find(dop.begin(), dop.end(), "push") != dop.end()) {
        it = std::find(dop.begin(), dop.end(), "push");
        return std::distance(dop.begin(), it) + 1;
    }

    if (std::find(dop.begin(), dop.end(), "get") != dop.end()) {
        it = std::find(dop.begin(), dop.end(), "get");
        return std::distance(dop.begin(), it) + 1;
    }

    if (std::find(dop.begin(), dop.end(), "length") != dop.end()) {
        it = std::find(dop.begin(), dop.end(), "length");
        return std::distance(dop.begin(), it) + 1;
    }

    return -1;
}

template <typename T>
bool QueueApp<T>::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        help(argv[0], "ERROR: Should be at least 3 arguments\n\n");
        return false;
    }

    if (findOperation(argc, argv) == -1) {
        help(argv[0], "ERROR: You need to enter an operation\n\n");
        return false;
    }
    return true;
}
template<typename T>
double QueueApp<T>::parseInt(const char* arg) {
    int result = 0;
    result = std::stoi(arg);
    return result;
}

template<typename T>
Operations QueueApp<T>::parseOperation(const char* arg) {
    Operations operation;

    if (arg[0] == 'p' && arg[1] == 'u' && arg[2] == 's' && arg[3] == 'h') {
        operation = Operations::push;
    } else if (arg[0] == 'p' && arg[1] == 'u' && arg[2]
    == 's' && arg[3] == 'h') {
        operation = Operations::pop;
    } else if (arg == "length") {
        operation = Operations::length;
    }
    return operation;
}

template<typename T>
std::string QueueApp<T>::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    int size = 0;
    bool withOperand = false;

    if (findOperation(argc, argv) == argc - 1) {
        size = argc - 2;
        withOperand = false;
    } else if (findOperation(argc, argv) == argc - 2) {
        size = argc - 3;
        withOperand = true;
    }

    TQueue<int> que(size);
    Operations operation;
    int operand;
    for (int i = 1; i <= size; ++i) {
            que.Push(parseInt(argv[i]));
        }

        if (!withOperand) {
            operation = parseOperation(argv[argc - 1]);
        } else {
            operation = parseOperation(argv[argc - 2]);
            operand = parseInt(argv[argc - 1]);
        }

    std::ostringstream stream;

    switch (operation) {
    case Operations::push:
        que.push(operand);
        stream << "queue: ";
        for (int i = 0; i < que.length(); i++)
            stream << que[i] << " ";
        break;
    case Operations::pop:
        stream << "pop element: " << std::to_string(que.pop());
        break;
    case Operations::length:
        stream << "queue length: " << std::to_string(que.length());
    }

    message_ = stream.str();
    return message_;
}
