// Copyright 2023 Prokofev Denis
#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

enum class Operations { push, pop, length };

template <class T>
class QueueApp {
    std::string message;
  struct node {
    T data;
    node* nextNode;
  };
  node* head;
  int size;

 public:
     QueueApp();
  void help();
  std::string operator()(int argc, const char** argv);
  int findOperation(int argc, const char** argv);
  bool validateNumberOfArguments(int argc, const char** argv);
  double parseInt(const char* arg);
  Operations parseOperation(const char* arg);
  ~QueueApp();
  void push(T e);
  T pop();
  int length();
};

template <typename T>
QueueApp<T>::QueueApp() {
  size = 0;
  head = nullptr;
}

template <typename T>
QueueApp<T>::~QueueApp() {
  node* temp;
  while (head != nullptr) {
    temp = head;
    head = head->nextNode;
    delete temp;
  }
}

template <typename T>
T QueueApp<T>::pop() {
  if (head == nullptr) {
    throw "exception";
  }

  node* temp = head;
  T data = head->data;
  head = head->nextNode;
  delete temp;
  size--;

  return data;
}

template <typename T>
void QueueApp<T>::push(T data) {
  node* newNode = new node;
  newNode->data = data;
  newNode->nextNode = nullptr;

  size++;

  if (head == nullptr) {
    head = newNode;
    return;
  }

  node* current = head;
  while (current != nullptr) {
    if (current->nextNode == nullptr) {
      current->nextNode = newNode;
      return;
    }

    current = current->nextNode;
  }
}

template <typename T>
int QueueApp<T>::length() {
  return size;
}
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

    if (std::find(dop.begin(), dop.end(), "pop") != dop.end()) {
        it = std::find(dop.begin(), dop.end(), "pop");
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
    } else if (arg[0] == 'l' && arg[1] == 'e' && arg[2] == 'n'
    && arg[3] == 'g' && arg[4] == 't' && arg[5] == 'h') {
        operation = Operations::length;
    }
    return operation;
}

template<typename T>
std::string QueueApp<T>::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message;
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

    QueueApp<T> que(size);
    Operations operation;
    int operand;
    for (int i = 1; i <= size; ++i) {
            que.push(parseInt(argv[i]));
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
        stream << "push " << operand;
        break;
    case Operations::pop:
        stream << "pop element: " << std::to_string(que.pop());
        break;
    case Operations::length:
        stream << "queue length: " << std::to_string(que.length());
    }

    message = stream.str();
    return message;
}

#endif  //  MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
