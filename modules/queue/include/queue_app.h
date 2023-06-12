// Copyright 2023 Prokofev Denis
#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

enum class Operations { push, pop, length };

template <class T>
class QueueApp {
    std::string message;
    std::string queueToString(QueueApp<int>* que);
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
  int parseInt(std::string s);
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
std::string QueueApp<T>::operator()(int argc, const char ** argv) {
  if (argc <= 2) {
    help();
    return message;
  }

  std::string op = argv[1];
  if (op == "push") {
    try {
      QueueApp <int> que;
      if (argc > 3) {
        for (int i = 3; i < argc; i++) {
          int element = std::stoi(argv[i]);
          que.push(element);
        }
      }
      int element = std::stoi(argv[2]);
      que.push(element);
      return queueToString( & que);
    } catch (std::invalid_argument & ) {
        message.append("Error: Invalid element.")
        .append(" Only integers are allowed. Command push.\n");
        return message;
    }
  } else if (op == "pop") {
    try {
      QueueApp <int> que;
      if (argc > 2) {
        for (int i = 2; i < argc; i++) {
          int element = std::stoi(argv[i]);
          que.push(element);
        }
      }
      que.pop();
      return queueToString( & que);
    } catch (std::invalid_argument & ) {
        message.append("Error: Invalid element.")
        .append(" Only integers are allowed. Command pop.\n");
        return message;
    }
  } else if (op == "length") {
    QueueApp < int > que;
    if (argc > 2) {
      for (int i = 2; i < argc; i++) {
        int element = std::stoi(argv[i]);
        que.push(element);
      }
    }
    message.append("Queue length: ").append(std::to_string(que.length()))
    .append("\n");
  } else {
    message.append("Error: operation.\n");
    help();
    return message;
  }
}

template <typename T>
std::string QueueApp<T>::queueToString(QueueApp < int > * que) {
  if (que -> length() == 0)
    return "The que is empty.\n";
  std::stringstream ss;
  ss << "The que is: { ";
  while (que -> length() != 0)
    ss << que -> pop() << " ";
  ss << "}";
  return ss.str();
}

#endif  //  MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
