#ifndef BLATT_BDD_STACK
#define BLATT_BDD_STACK

#include <gtest/gtest.h>

#include "board.hpp"

template <typename T>
class Stack {
 public:
  Stack() : size(0), capacity(1), stack(nullptr) {}

  ~Stack() { delete[] stack; }

  // push the element to the stack
  void push(const T &pos);

  // last element added
  T top() const;

  // deletes the last inserted element of the stack
  void pop();

  // checks if the stack is empty
  bool empty() const;

  // resize to match the capacity if required
  void reserve(int n);

  const T operator[](int n) const { return stack[n]; }

  int number_of_elements() const { return size; }

 private:
  int size;
  int capacity;
  T *stack;

  FRIEND_TEST(StackTest, pushTest);
};

#endif
