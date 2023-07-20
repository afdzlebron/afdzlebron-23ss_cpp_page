#include "stack.hpp"

template <typename T>
void Stack<T>::reserve(int n) {
  if (n < capacity) return;

  capacity = n;
  T* newStack = new T[n];
  for (int i = 0; i < size; ++i) newStack[i] = stack[i];

  delete[] stack;
  stack = newStack;
}

template <typename T>
void Stack<T>::push(const T& item) {
  if (size + 1 >= capacity) reserve(2 * capacity);

  assert(size < capacity);
  stack[size] = item;
  ++size;
}

template <typename T>
void Stack<T>::pop() {
  if (!size) return;
  --size;
}

template <typename T>
T Stack<T>::top() const {
  return stack[size - 1];
}

template <typename T>
bool Stack<T>::empty() const {
  return size == 0;
}

template class Stack<Board>;
