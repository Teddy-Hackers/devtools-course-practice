// Copyright 2023 Prokofev Denis
#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>

enum class Operations { push, pop, length };

template <class T>
class QueueApp {
    std::string message;
    std::string queueToString(QueueApp<int>* queue);
    std::string getHelpMessage();
  struct node {
    T data;
    node* nextNode;
  };
  node* head;
  int size;
 public:
     QueueApp();
  void help();
  std::string executeCommand(int argc, const char** argv);
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
std::string QueueApp<T>::executeCommand(int argc, const char ** argv) {
  if (argc == 1)
    return getHelpMessage();
  if (argc <= 2) {
    std::stringstream ss;
    ss << "Error: No elements provided.\n" <<
      getHelpMessage();
    return ss.str();
  }

  std::string command = argv[1];
  if (command == "push") {
    try {
      QueueApp < int > queue;
      if (argc > 3) {
        for (int i = 3; i < argc; i++) {
          int element = std::stoi(argv[i]);
          queue.push(element);
        }
      }
      int element = std::stoi(argv[2]);
      queue.push(element);
      return queueToString( & queue);
    } catch (std::invalid_argument & ) {
        std::stringstream ss;
        ss << "Error: Invalid element."
           << " Only integers are allowed. Command push.\n";
        return ss.str();
    }
  } else if (command == "pop") {
    try {
      QueueApp < int > queue;
      if (argc >= 3) {
        for (int i = 2; i < argc; i++) {
          int element = std::stoi(argv[i]);
          queue.push(element);
        }
      }
      queue.pop();
      return queueToString( & queue);
    } catch (std::invalid_argument & ) {
        std::stringstream ss;
        ss << "Error: Invalid element."
           << " Only integers are allowed. Command pop.\n";
        return ss.str();
    }
  } else if (command == "length") {
    QueueApp < int > queue;
    if (argc >= 3) {
      for (int i = 2; i < argc; i++) {
        int element = std::stoi(argv[i]);
        queue.push(element);
      }
    }
    return "Queue length: " + std::to_string(queue.length()) + "\n";
  } else {
    std::stringstream ss;
    ss << "Error: Invalid command.\n" <<
      getHelpMessage();
    return ss.str();
  }
}

template <typename T>
std::string QueueApp<T>::queueToString(QueueApp < int > * queue) {
  if (queue -> length() == 0)
    return "The queue is empty.\n";
  std::stringstream ss;
  ss << "The queue is: { ";
  while (queue -> length() != 0)
    ss << queue -> pop() << " ";
  ss << "}";
  return ss.str();
}

template <typename T>
std::string QueueApp<T>::getHelpMessage() {
  std::stringstream ss;
  ss << "Available commands:\n" <<
      "  push <element> : Push an element to the queue." <<
      " example: push 5 1 2 3 4\n" <<
      "  pop : Pop an element from the queue. example: pop 1 2 3 4\n" <<
      "  length : Get the length of the queue. example: length 1 2 3 4\n";
  return ss.str();
}
#endif  //  MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
