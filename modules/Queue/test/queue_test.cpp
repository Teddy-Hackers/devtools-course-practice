  // Copyright 2023 Sudomoykin Andrey

#include "../include/queue.h"
#include <gtest/gtest.h>

TEST(MyQueue, can_push) {
  Queue<int> queue;
  ASSERT_NO_THROW(queue.push(2));
}

TEST(MyQueue, can_pop) {
  Queue<int> queue;
  queue.push(1);
  EXPECT_EQ(1, queue.popit());
}

TEST(MyQueue, can_get_lenght) {
  Queue<int> queue;
  queue.push(1);
  queue.push(2);
  EXPECT_EQ(2, queue.length());
}
