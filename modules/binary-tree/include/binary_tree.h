//  Copyright 2023 Semenova Veronika

#ifndef MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
#define MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_

#include <exception>
#include <vector>
#include <stack>

struct Node {
  int Value;
  Node *Left;
  Node *Right;
  Node *Parent;

  explicit Node(int V = 0.0, Node *P = nullptr,
                Node *L = nullptr, Node *R = nullptr);
  Node(const Node &n);
};

class BinaryTree {
  Node *root;
  Node *curr;
  static Node *FindMin(Node *node);
  static Node *FindMax(Node *node);
  static Node *FindNext(Node *node);
 public:
  BinaryTree();
  explicit BinaryTree(int v);
  explicit BinaryTree(const std::vector<int> &v);
  ~BinaryTree();

  Node *Find(int k) const;
  void Insert(int k);
  void Delete(int k);

  int GetValue() const;
  void Reset();
  void SetNext();
  bool IsEnd() const;
  bool IsEmpty() const;
};

#endif  //  MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
