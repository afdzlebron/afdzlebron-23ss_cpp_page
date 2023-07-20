#include "stack.hpp"

void Stack::reserve(int n) {
  if (n > capacity) {
    capacity = n;
    Board *new_stack = new Board[capacity];
    for (int i = 0; i < size; ++i) {
      new_stack[i] = stack[i];
    }
    delete[] stack;
    stack = new_stack;
  }
}

void Stack::push(const Board &pos) {
  if (size == capacity) {
    reserve(2 * capacity);
  }
  stack[size] = pos;
  ++size;
}

Board Stack::top() const {
  assert(size > 0);
  return stack[size - 1];
}

void Stack::pop() {
  if (size > 0) {
    --size;
  }
}

bool Stack::empty() const { return size == 0; }