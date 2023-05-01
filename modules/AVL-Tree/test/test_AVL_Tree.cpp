// Copyright 2023 Ermolaev Danila

#include <gtest/gtest.h>
#include <string>
#include "include/AVLTree.h"

TEST(AVLTree, can_create_avl_tree) { ASSERT_NO_THROW( AVLTree<int> testavl;); }
