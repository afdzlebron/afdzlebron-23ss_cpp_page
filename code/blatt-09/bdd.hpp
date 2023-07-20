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
//
//  - Nodes can be connected via `connect_true' and `connect_false' (for
//  connection to true or
//  - false) and `connect' to connect two nodes
//
//
// Internally, all nodes are stored in the `nodes' vector in order do be able to
// destray all the nodes.
class BDD {
 public:
  BDD() : fresh_id(0), root(nullptr) {}

  BDD(const BDD &) = delete;
  BDD(BDD &&) = delete;

  // This function imports a Board and returns a node. The successors of the
  // nodes are set to the false node automatically.
  Node *import_node(const Board &b);

  // destructor
  ~BDD() {
    for (std::vector<Node *>::size_type i = 0; i < nodes.size(); ++i) {
      delete nodes[i];
    }
  }

  friend class Node;

  // connect two nodes together
  // overwriting any existing relationships.
  void connect(Node *parent, Node *children, bool if_true);

  // connect the node to the true or false node assuming that parent is valid
  // pointer to a node (neither true nor false)
  void connect_true(Node *parent, bool if_true);
  void connect_false(Node *parent, bool if_true);

  // counts the number of paths leading to true
  int count_true_path() const;

  // Write the graph as a dot (graphviz) file.
  friend std::ostream &operator<<(std::ostream &stream, const BDD &bdd);

 private:
  // we number of nodes starting from 0 upwards.
  int fresh_id;

  // Root node. If our BDD contains any node, then one of them is the root file.
  Node *root;

  // This are two specific nodes, true or false. These nodes have a specific
  // meaning and should not be seen as nodes that can be dereferenced.
  Node *const true_node = (Node *)1;
  Node *const false_node = (Node *)2;

  // A list of all nodes within the class.
  std::vector<Node *> nodes;

  FRIEND_TEST(BDDTest, basicTest);
};

#endif
