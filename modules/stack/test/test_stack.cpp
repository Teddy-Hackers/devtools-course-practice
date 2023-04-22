// Copyright 2023 Kandrin Alexey

#include <gtest/gtest.h>

#include "include/stack.h"

TEST(Kandrin_Alexey_StackTest, Cant_get_top_element_from_empty_stack)
{
    // Arrange
    Stack<int> stack;
    
    // Act & assert
    ASSERT_ANY_THROW(stack.top());
}

TEST(Kandrin_Alexey_StackTest, Cant_get_const_top_element_from_empty_stack)
{
    // Arrange
    Stack<int> stack;

    // Act & assert
    ASSERT_ANY_THROW(const_cast<const Stack<int> &>(stack).top());
}

TEST(Kandrin_Alexey_StackTest, Can_get_top_element_from_non_empty_stack)
{
    // Arrange
    Stack<int> stack;
    int value = 7;
    stack.push(value);

    // Act & assert
    ASSERT_EQ(value, stack.top());
}

TEST(Kandrin_Alexey_StackTest, Can_get_const_top_element_from_non_empty_stack)
{
    // Arrange
    Stack<int> stack;
    int value = 7;
    stack.push(value);

    // Act & assert
    ASSERT_EQ(value, const_cast<const Stack<int> &>(stack).top());
}

TEST(Kandrin_Alexey_StackTest, Top_element_returns_last_pushed_value)
{
    // Arrange
    Stack<int> stack;

    // Act & assert
    for (int i = 0; i < 5; ++i)
    {
        stack.push(i);
        ASSERT_EQ(i, stack.top());
    }
}

TEST(Kandrin_Alexey_StackTest, Const_top_element_returns_last_pushed_value)
{
    // Arrange
    Stack<int> stack;

    // Act & assert
    for (int i = 0; i < 5; ++i)
    {
        stack.push(i);
        ASSERT_EQ(i, const_cast<const Stack<int> &>(stack).top());
    }
}

TEST(Kandrin_Alexey_StackTest, Default_constructor_gives_empty_stack)
{
    // Arrange
    Stack<int> stack;

    // Act & assert
    ASSERT_TRUE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Stack_is_not_empty_after_push)
{
    // Arrange
    Stack<int> stack;
    
    // Act
    stack.push(1);

    // Assert
    ASSERT_FALSE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Stack_is_empty_after_pop)
{
    // Arrange
    Stack<int> stack;
    stack.push(1);

    // Act
    stack.pop();

    // Assert
    ASSERT_TRUE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Stack_is_not_empty_after_pop)
{
    // Arrange
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

    // Act
    stack.pop();

    // Assert
    ASSERT_FALSE(stack.empty());
}
