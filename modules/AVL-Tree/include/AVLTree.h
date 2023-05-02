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
  void insertRecurse(const TData& value, AVLNode*currNode);
  void singleLeftShift(AVLNode*node);
  int findHeight(AVLNode* node) const;
  int max(int a, int b);
  void balance(AVLNode*node);
  void singleRightShift(AVLNode*node);
  void removeRecurse(const TData& value, AVLNode*current);
  TData& recurse_find_min(AVLNode* node) const;
  TData& recurse_find_max(AVLNode* node) const;
  void printRecurse(AVLNode* node, int count, std::ostream& os) const;
  void emptyRecurse(AVLNode*node);
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

template <typename TData>
bool AVLTree<TData>::containRecurse(AVLNode* node,
                                         const TData& value) const {
  if (node) {
    if (node->value == value) {
      return true;
    } else if (value < node->value) {
      return containRecurse(node->left, value);
    } else if (value > node->value) {
      return containRecurse(node->right, value);
    }
  }

  return false;
}

template <typename TData>
void AVLTree<TData>::insert(const TData& value) {
  insertRecurse(value, root);
}

template <typename TData>
void AVLTree<TData>::insertRecurse(const TData& value,
                                        AVLNode*currNode) {
  if (currNode == nullptr) {
    currNode = new AVLNode(value);
  } else if (value < currNode->value) {
    insertRecurse(value, currNode->left);
  } else if (value > currNode->value) {
    insertRecurse(value, currNode->right);
  }

  balance(currNode);
}

template <typename TData>
void AVLTree<TData>::remove(const TData& value) {
  removeRecurse(value, this->root);
}

template <typename TData>
void AVLTree<TData>::removeRecurse(const TData& value,
                                        AVLNode*current) {
  if (!current) {
    return;
  }

  if (value == current->value) {
    if (current->left == nullptr && current->right == nullptr) {
      delete current;
      current = nullptr;
    } else if (current->left && current->right) {
      TData& minRight = recurse_find_min(current->right);
      current->value = minRight;
      removeRecurse(minRight, current->right);
    } else if (current->right || current->left) {
      AVLNode* temp = current;
      if (current->right) {
        current = current->right;
        delete temp;
      } else {
        current = current->left;
        delete temp;
      }
    }
  } else if (value < current->value) {
    removeRecurse(value, current->left);
  } else {
    removeRecurse(value, current->right);
  }

  balance(current);
}

template <typename TData>
const TData& AVLTree<TData>::find_min() const {
  return recurse_find_min(root);
}

template <typename TData>
TData& AVLTree<TData>::recurse_find_min(AVLNode* node) const {
  if (!node) {
    throw std::invalid_argument("Tree is empty, no minimum value.");
  }

  if (node->left == nullptr) {
    return node->value;
  }
  return recurse_find_min(node->left);
}

template <typename TData>
const TData& AVLTree<TData>::find_max() const {
  return recurse_find_max(this->root);
}

template <typename TData>
TData& AVLTree<TData>::recurse_find_max(AVLNode* node) const {
  if (!node) {
    throw std::invalid_argument("Tree is empty, no maximum value.");
  }

  if (node->right == nullptr) {
    return node->value;
  }

  return recurse_find_max(node->right);
}

template <typename TData>
void AVLTree<TData>::print_tree(std::ostream& os) const {
  if (this->root == nullptr) {
    os << "<empty>" << std::endl;
  }

  int count = -1;
  printRecurse(root, count, os);
}

template <typename TData>
void AVLTree<TData>::printRecurse(AVLNode* node, int count,
                                       std::ostream& os) const {
  if (node) {
    count++;

    printRecurse(node->right, count, os);

    if (node != root) {
      for (int i = 0; i < count * 2; i++) {
        os << " ";
      }
    }

    os << node->value << std::endl;
    printRecurse(node->left, count, os);
  }
}

template <typename TData>
bool AVLTree<TData>::is_empty() const {
  return (root == nullptr);
}

template <typename TData>
void AVLTree<TData>::make_empty() {
  emptyRecurse(root);
}

template <typename TData>
void AVLTree<TData>::emptyRecurse(AVLNode*node) {
  if (node) {
    emptyRecurse(node->left);
    emptyRecurse(node->right);
    delete node;
  }

  node = nullptr;
}

template <typename TData>
int AVLTree<TData>::findHeight(AVLNode* node) const {
  return !node ? -1 : node->height;
}

template <typename TData>
int AVLTree<TData>::max(int a, int b) {
  return a > b ? a : b;
}

template <typename TData>
void AVLTree<TData>::preorderInsert(AVLNode* current) {
  if (current) {
    this->insert(current->value);
    this->preorderInsert(current->left);
    this->preorderInsert(current->right);
  }

  return;
}

template <typename TData>
void AVLTree<TData>::balance(AVLNode*node) {
  if (!node) {
    return;
  }

  int factor = findHeight(node->left) - findHeight(node->right);

  if (factor < -1) {
    if (findHeight(node->right->right) >= findHeight(node->right->left)) {
      singleLeftShift(node);
    } else {
      singleRightShift(node->right);
      singleLeftShift(node);
    }
  } else if (factor > 1) {
    if (findHeight(node->left->left) >= findHeight(node->left->right)) {
      singleRightShift(node);
    } else {
      singleLeftShift(node->left);
      singleRightShift(node);
    }
  }

  node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
}

template <typename TData>
void AVLTree<TData>::singleLeftShift(AVLNode*node) {
  AVLNode* nodeRight = node->right;

  node->right = nodeRight->left;
  nodeRight->left = node;

  node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
  nodeRight->height =
      max(findHeight(nodeRight->left), findHeight(nodeRight->right)) + 1;

  node = nodeRight;
}

template <typename TData>
void AVLTree<TData>::singleRightShift(AVLNode*node) {
  AVLNode* nodeLeft = node->left;

  node->left = nodeLeft->right;
  nodeLeft->right = node;

  node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
  nodeLeft->height =
      max(findHeight(nodeLeft->left), findHeight(nodeLeft->right)) + 1;

  node = nodeLeft;
}

