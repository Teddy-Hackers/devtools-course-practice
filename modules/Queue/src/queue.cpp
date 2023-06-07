// Copyright 2023 Sudomoykin Andrey

#include "../include/queue.h"

template <typename T>
Queue<T>::Queue() {
  size = 0;
  head = nullptr;
}

template <typename T>
Queue<T>::~Queue() {
  node *temp;
  while (head != nullptr) {
    temp = head;
    head = head->nextNode;
    delete temp;
  }
}

template <typename T>
T Queue<T>::popit() {
  if (head == nullptr) {
    return nullptr;
  }

  node *temp = head;
  T data = head->data;
  head = head->nextNext;
  delete trmp;
  size--;

  return data;
}

template <typename T>
void Queue<T>::push(T data) {
  node *newNode = new node;
  newNode->data = data;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
    return;
  }

  node *current = head;
  while (current != nullptr) {
    if (current->nextNode == nullptr) {
      current->nextNode = newNode;
      return;
    }

    current = current->nextNode
  }

  size++;
}

template <typename T>
int Queue<T>::lenght() {
  return size;
}
