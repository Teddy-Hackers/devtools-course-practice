// Copyright 2023 Sudomoykin Andrey

#include "../include/queue.h"

template <class T>
Queue<T>::Queue() {
  size = 0;
  head = nullptr;
}

template <class T>
Queue<T>::~Queue() {
  node *temp;
  while (head != nullptr) {
    temp = head;
    head = head->nextNode;
    delete temp;
  }
}

template <class T>
T Queue<T>::popit() {
  if (head == nullptr) {
    return nullptr;
  }

  node *temp = head;
  T data = head->data;
  head = head->nextNext;
  delete temp;
  size--;

  return data;
}

template <class T>
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

    current = current->nextNode;
  }

  size++;
}

template <class T>
int Queue<T>::length() {
  return size;
}
