// Copyright 2023 Prokofev Denis
#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <stdio.h>
#include <string>

enum class Operations { push, get, length };

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
  int lenght();
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
int QueueApp<T>::lenght() {
  return size;
}

#endif  //  MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
