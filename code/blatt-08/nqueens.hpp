#ifndef BLATT_BDD_NQUEENS
#define BLATT_BDD_NQUEENS

#include <stack>

#include "bdd.hpp"

class NQueens {
public:
  NQueens(int n) : size(n) { construct_bdd(); }

  int count_solutions() { return bdd.count_true_path(); }

private:
  // construct the internal representation of the n-queens problem
  void construct_bdd();

  // connect parent to its child (true or false depending on direction) and
  // pushing the node to the stack
  void check_and_add_child(Node *parent, bool direction,
                           std::stack<Node *> &stack);
  int size;
  BDD bdd;
};
#endif