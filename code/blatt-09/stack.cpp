#include "stack.hpp"

#include "board.hpp"
#include "node.hpp"

template <typename T>
void Stack<T>::reserve(int n) {
  if (n < capacity) return;

  capacity = n;
  T *nb = new T[n];
  for (int i = 0; i < size; ++i) nb[i] = stack[i];

  delete[] stack;
  stack = nb;
}

template <typename T>
void Stack<T>::push(const T &board) {
  if (size + 1 >= capacity) reserve(2 * capacity);

  assert(size < capacity);
  stack[size] = std::move(board);
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

// instantiation
template class Stack<Node *>;
template class Stack<Board *>;
template class Stack<Board>;