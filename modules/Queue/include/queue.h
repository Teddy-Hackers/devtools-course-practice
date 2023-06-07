// Copyright 2023 Sudomoykin Andrey

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

template <typename T>
class Queue {
  struct node {
    T data;
    node* nextNode;
  };
  node* head;
  int size;

 public:
  Queue();
  ~Queue();
  void push(T e);
  T popit();
  int lenght();
};
#endif