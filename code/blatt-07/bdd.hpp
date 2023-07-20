#ifndef BLATT_BDD_BDD
#define BLATT_BDD_BDD

#include <gtest/gtest.h>

#include <ostream>
#include <vector>

#include "node.hpp"

// This is a very simple implementation of a BDD (binary decision diagram).
//
// There are two special nodes `true_node' and `false_node' that represent 1 and
// 0 of the BDD.
//
// The interface is very simple in order to construct the BDD:
//
//  - it is possible to import a Board. This returns the node as imported by the
//  BDD
//  - Nodes can be connected via `connect_true' and `connect_false'
//
//
// Internally, all nodes are stored in the `nodes' vector in order do be able to
// destray all the nodes.
class BDD {
 public:
  BDD() : fresh_id(0), root(nullptr) {}

  Node *import_node(const Board &b);

  ~BDD() {
    for (auto &n : nodes) delete n;
  }

  friend class Node;

  // connect two nodes together
  // assuming that parent does not have a children already
  void connect(Node *parent, Node *children, bool if_true);

  // connect to true or false
  void connect_true(Node *parent, bool if_true);
  void connect_false(Node *parent, bool if_true);

  // counts the number of paths leading to true
  int count_true_path() const;

  // Write the graph as a dot (graphviz) file.
  friend std::ostream &operator<<(std::ostream &stream, const BDD &bdd);

  // write the BDD into file provided by the argument
  void write_dot_file(std::string file) const;

 private:
  int fresh_id;
  Node *root;
  Node *const true_node = (Node *)1;
  Node *const false_node = (Node *)2;
  std::vector<Node *> nodes;
  FRIEND_TEST(BDDTest, basicTest);
};

#endif
