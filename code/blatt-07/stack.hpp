#ifndef BLATT_BDD_STACK
#define BLATT_BDD_STACK

#include <gtest/gtest.h>

#include "board.hpp"

class Stack {
 public:
  Stack() : size(0), capacity(1), stack(nullptr) {}

  ~Stack() {
    /*TODO: Übungsblatt 7, Aufgabe 2*/
    assert(false);
  }

  // push the element to the stack
  void push(const Board &pos);

  // last element added
  Board top() const;

  // deletes the last inserted element of the stack
  void pop();

  // checks if the stack is empty
  bool empty() const;

  // resize to match the capacity if required
  void reserve(int n);

 private:
  int size;
  int capacity;
  Board *stack;

  FRIEND_TEST(StackTest, pushTest);
};
#endif
