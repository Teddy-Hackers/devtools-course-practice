// Copyright 2023 Zorin Oleg

#include <gtest/gtest.h>

#include "include/priority_queue.h"

class PriorityQueueIntTest : public ::testing::Test {
 protected:
  PriorityQueue<int> Q;
  virtual void SetUp() {
    Q.put(15);
    Q.put(1);
    Q.put(-3);
    Q.put(100);
    Q.put(10);
    Q.put(-2);
    Q.put(-15);
  }
  virtual void TearDown() {

  }
};

TEST(PriorityQueueTest, Size_Null_When_Empty) {
  PriorityQueue<int> Q;

  size_t size = Q.size();

  ASSERT_EQ((size_t) 0, size);
}

TEST(PriorityQueueTest, Can_Put_One_Element) {
  PriorityQueue<int> Q;
  const int value = 5;

  Q.put(value);

  ASSERT_EQ(value, Q.top());
}

TEST(PriorityQueueTest, Can_Get) {
  PriorityQueue<int> Q;
  const int expectedValue = 5;
  Q.put(expectedValue);

  const int value = Q.get();

  ASSERT_EQ(expectedValue, value);
}

TEST(PriorityQueueTest, Empty_When_Pop_Remove_Last_Element) {
  PriorityQueue<int> Q;
  const int value = 5;
  Q.put(value);

  Q.pop();

  ASSERT_TRUE(Q.empty());
}

TEST(PriorityQueueTest, Empty_When_Get_Remove_Last_Element) {
  PriorityQueue<int> Q;
  const int value = 5;
  Q.put(value);

  Q.get();

  ASSERT_TRUE(Q.empty());
}

TEST_F(PriorityQueueIntTest, Top_Return_Highest_Element) {
  ASSERT_EQ(100, Q.top());
}

TEST_F(PriorityQueueIntTest, Get_Return_Highest_Element) {
  ASSERT_EQ(100, Q.get());
}

TEST_F(PriorityQueueIntTest, Pop_Remove_Highest_Element) {
  Q.pop();

  ASSERT_NE(100, Q.top());
}

TEST_F(PriorityQueueIntTest, Pop_Change_Size) {
  size_t size = Q.size();

  Q.pop();

  ASSERT_EQ(size - 1, Q.size());
}

TEST_F(PriorityQueueIntTest, Get_Change_Size) {
  size_t size = Q.size();

  int value = Q.get();

  ASSERT_EQ(size - 1, Q.size());
}

TEST_F(PriorityQueueIntTest, Top_Not_Change_Size) {
  size_t size = Q.size();

  const int &value = Q.top();

  ASSERT_EQ(size, Q.size());
}

TEST_F(PriorityQueueIntTest, Empty_When_Clear) {
  Q.clear();

  ASSERT_TRUE(Q.empty());
}
