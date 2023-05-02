// Copyright 2023 Ermolaev Danila

#include <gtest/gtest.h>
#include <string>
#include "include/AVLTree.h"

TEST(AVLTree, can_create_avl_tree) { ASSERT_NO_THROW(AVLTree<int> testavl;); }

TEST(AVLTree, can_insert_elements) {
  AVLTree<int> testavl;
  ASSERT_NO_THROW(testavl.insert(10););
}

TEST(AVLTree, can_create_avl_tree_copy_constructor) {
  AVLTree<int> testavl;
  testavl.insert(10);

  ASSERT_NO_THROW(AVLTree<int> testavl2(testavl););
}

TEST(AVLTree, can_find_element) {
  AVLTree<int> testavl;
  testavl.insert(10);
  testavl.insert(20);
  testavl.insert(12);
  testavl.insert(15);
  testavl.insert(16);
  testavl.insert(18);

  EXPECT_TRUE(testavl.contains(20));
}
TEST(AVLTree, can_find_max) {
  AVLTree<int> testavl;
  testavl.insert(10);
  testavl.insert(20);
  testavl.insert(12);
  testavl.insert(15);
  testavl.insert(16);
  testavl.insert(18);

  EXPECT_EQ(20, testavl.find_max());
}
TEST(AVLTree, can_find_min) {
  AVLTree<int> testavl;
  testavl.insert(10);
  testavl.insert(20);
  testavl.insert(12);
  testavl.insert(15);
  testavl.insert(16);
  testavl.insert(18);

  EXPECT_EQ(10, testavl.find_min());
}
TEST(AVLTree, can_check_empty) {
  AVLTree<int> testavl;
  EXPECT_TRUE(testavl.is_empty());
}
TEST(AVLTree, can_make_empty) {
  AVLTree<int> testavl;
  testavl.insert(10);
  testavl.insert(20);
  testavl.insert(12);
  testavl.insert(15);
  testavl.insert(16);
  testavl.insert(18);
  testavl.make_empty();
  EXPECT_TRUE(testavl.is_empty());
}
