// Copyright 2023 Ermolaev Danila

#pragma once
#include <cstddef>
#include <iostream>
#include <algorithm>

template <typename TData>
class AVLTree {
 public:
  AVLTree();
  explicit AVLTree(const AVLTree& other);
  ~AVLTree();
  AVLTree& operator=(const AVLTree& other);
  bool contains(const TData& value) const;
  void insert(const TData& value);
  void remove(const TData& value);
  const TData& find_min() const;
  const TData& find_max() const;
  void print_tree(std::ostream& os = std::cout) const;
  bool is_empty() const;
  void make_empty();

 private:
  struct AVLNode {
    int height;
    AVLNode* left;
    AVLNode* right;
    TData value;
    AVLNode()
        : height(0), left(nullptr), right(nullptr), value() {}
    explicit AVLNode(TData value)
        : height(0), left(nullptr), right(nullptr), value(value) {}
  };

  AVLNode* root;

  void preorderInsert(AVLNode* current);
  void insertRecurse(const TData& value, AVLNode**currNode);
  void singleLeftShift(AVLNode**node);
  int findHeight(AVLNode* node) const;
  int max(int a, int b);
  void balance(AVLNode**node);
  void singleRightShift(AVLNode**node);
  void removeRecurse(const TData& value, AVLNode**current);
  TData& recurse_find_min(AVLNode* node) const;
  TData& recurse_find_max(AVLNode* node) const;
  void printRecurse(AVLNode* node, int count, std::ostream& os) const;
  void emptyRecurse(AVLNode**node);
  bool containRecurse(AVLNode* node, const TData& value) const;
};

template <typename TData>
AVLTree<TData>::AVLTree()
    : root(nullptr) {}

template <typename TData>
AVLTree<TData>::AVLTree(const AVLTree& other)
    : root(nullptr) {
  if (other.root != nullptr) {
    this->preorderInsert(other.root);
  }
}

template <typename TData>
AVLTree<TData>::~AVLTree() {
  make_empty();
}

template <typename TData>
AVLTree<TData>& AVLTree<TData>::operator=(const AVLTree& other) {
  if (this == &other) {
    return *this;
  }

  this->make_empty();

  if (other.root == nullptr) {
    this->root = nullptr;
    return *this;
  }

  this->preorderInsert(other.root);
  return *this;
}

