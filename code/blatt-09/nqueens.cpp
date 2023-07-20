#include "nqueens.hpp"

#include <fstream>
#include <stack>

// connect Node parent to its child (direction true or false) and pushing the
// node to the stack if needed
void NQueens::check_and_add_child(Node *parent, bool direction,
                                  std::stack<Node *> &stack) {
  Board b = parent->get_configuration();
  if (!b.has_next(direction)) {
    if (direction) {
      bdd.connect_true(parent, true);
    } else {
      bdd.connect_false(parent, false);
    }
    return;
  }
  b.next(direction);
  if (!b.is_valid()) {
    if (direction) {
      bdd.connect_false(parent, true);
    } else {
      bdd.connect_false(parent, false);
    }
    return;
  }
  Node *child = bdd.import_node(b);
  stack.push(child);
  bdd.connect(parent, child, direction);
}
void NQueens::construct_bdd() {
  Board b(size);
  std::stack<Node *> stack;
  Node *root = bdd.import_node(b);
  stack.push(root);

  while (!stack.empty()) {
    Node *parent = stack.top();
    stack.pop();
    check_and_add_child(parent, true, stack);
    check_and_add_child(parent, false, stack);
  }
}