// Copyright 2023 Eremin Aleksandr

#include <gtest/gtest.h>

#include "include/List.h"

TEST(Node, can_correctly_create_a_node) {
    ASSERT_NO_THROW(Node < int > a);
}

TEST(Node, can_correctly_create_a_node_with_data) {
    ASSERT_NO_THROW(Node < int > a(5, nullptr));
}

TEST(Node, can_correctly_create_node_copy) {
    Node < int > a;
    ASSERT_NO_THROW(Node < int > b(a));
}

TEST(List, can_correctly_create_list) {
    ASSERT_NO_THROW(List < double > l);
}

TEST(List, can_correctly_create_node_copy) {
    List < double > a;
    ASSERT_NO_THROW(List < double > b(a));
}

TEST(List, can_assign_two_empty_lists) {
    List < int > l2;
    List < int > l1;
    ASSERT_NO_THROW(l1 = l2);
}

TEST(List, new_list_is_empty) {
    List < double > l;
    EXPECT_DOUBLE_EQ(true, l.isEmpty());
}

TEST(List, size_of_new_list_is_zero) {
    List < double > l;
    EXPECT_DOUBLE_EQ(0.0, l.GetSize());
}

TEST(List, can_add_first_element_to_empty_list) {
    List < double > l;
    ASSERT_NO_THROW(l.InsertToHead(4));
}

TEST(List, can_add_to_head_elem_to_not_empty_list) {
    List < int > l;
    l.InsertToHead(4);
    l.InsertToHead(5);
    EXPECT_EQ(5, l.ViewHead());
}

TEST(List, can_add_to_tail_to_empty_list) {
    List < int > l;
    l.InsertToTail(4);
    EXPECT_EQ(4, l.ViewHead());
}

TEST(List, can_add_to_tail_not_empty_list) {
    List < int > l;
    l.InsertToTail(4);
    l.InsertToTail(5);
    l.InsertToTail(6);
    EXPECT_EQ(4, l.ViewHead());
}

TEST(List, can_find_the_element) {
    List < int > l;
    l.InsertToTail(1);
    l.InsertToTail(2);
    l.InsertToTail(3);
    Node < int >* p = l.Search(3);
    Node < int >* ptrue = l.GetHead()->next->next;
    EXPECT_EQ(ptrue, p);
}

TEST(List, can_insert_element_after_a_node) {
    List < int > l;
    l.InsertToTail(4);
    l.InsertToTail(5);
    l.InsertToTail(6);
    Node < int >* p = l.Search(4);
    ASSERT_NO_THROW(l.InsertAfter(p, 7));
}

TEST(List, correctly_determines_the_size) {
    List < int > l;
    l.InsertToTail(4);
    l.InsertToTail(5);
    l.InsertToTail(6);
    EXPECT_EQ(3, l.GetSize());
}

TEST(List, can_delete_element) {
    List < int > l;
    l.InsertToTail(3);
    l.InsertToTail(4);
    l.InsertToTail(5);
    l.InsertToTail(6);
    l.InsertToTail(7);
    ASSERT_NO_THROW(l.Delete(5));
}

TEST(List, can_delete_first_element) {
    List < int > l;
    l.InsertToTail(4);
    l.InsertToTail(5);
    l.InsertToTail(6);
    ASSERT_NO_THROW(l.Delete(6));
}

TEST(List, can_clean_empty_list) {
    List < int > l;
    ASSERT_NO_THROW(l.Clean());
}

TEST(List, can_clean_not_empty_list) {
    List < int > l;
    l.InsertToTail(4);
    l.InsertToTail(5);
    l.Clean();
    EXPECT_EQ(true, l.isEmpty());
}

TEST(List, can_copy_not_empty_list) {
    List < int > l;
    l.InsertToTail(4);
    l.InsertToTail(5);
    ASSERT_NO_THROW(List < int > l2(l));
}

TEST(List, three_nodes_list_is_correct) {
    List < int > l;
    l.InsertToTail(1);
    l.InsertToTail(2);
    l.InsertToTail(3);
    EXPECT_EQ(1, l.GetHead()->data);
    EXPECT_EQ(2, l.GetHead()->next->data);
    EXPECT_EQ(3, l.GetHead()->next->next->data);
    EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}

TEST(List, insert_after_ptr_for_not_empty_list_is_correct) {
    List < int > l;
    l.InsertToTail(1);
    l.InsertToTail(2);
    l.InsertToTail(3);
    Node < int >* p = l.GetHead()->next;
    l.InsertAfter(p, 5);
    EXPECT_EQ(2, l.GetHead()->next->data);
    EXPECT_EQ(5, l.GetHead()->next->next->data);
    EXPECT_EQ(3, l.GetHead()->next->next->next->data);
    EXPECT_EQ(NULL, l.GetHead()->next->next->next->next);
}

TEST(List, can_assign_two_not_empty_lists) {
    List < int > l;
    l.InsertToTail(1);
    l.InsertToTail(2);
    l.InsertToTail(3);
    List < int > l2;
    l2.InsertToTail(22);
    l2.InsertToTail(33);
    ASSERT_NO_THROW(l = l2);
}

TEST(List, can_assign_two_lists_list2_empty) {
    List < int > l;
    l.InsertToTail(1);
    l.InsertToTail(2);
    l.InsertToTail(3);
    List < int > l2;
    ASSERT_NO_THROW(l = l2);
}
