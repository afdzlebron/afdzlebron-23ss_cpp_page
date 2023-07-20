#ifndef BLATT_BDD_NODE
#define BLATT_BDD_NODE

#include "board.hpp"

// Node in the BDD
//
// It contains 2 informations, the position and an id to help debugging
// We initialize the successor to be the null pointer.
class Node {
 public:
  Node(int fresh_id, const Board &config)
      : id(fresh_id), configuration(config), if_true(nullptr) {}
  Node(int fresh_id, Board &&config)
      : id(fresh_id), configuration(config), if_true(nullptr) {}

 public:
  // identifier used whenever we need a number or something to distinguish it
  // from other nodes.
  const int id;

  // brind the content of
  friend std::ostream &operator<<(std::ostream &stream, const Node &bdd);

  // returns a copy of the configuration
  Board get_configuration() const { return configuration; };

 private:
  Board configuration;

 public:
  // connection to the two successors when taken and when not taken
  Node *if_true;
  Node *if_false;

  // flag indicating whether we should delete the node
  bool to_delete = false;

  bool operator==(const Node &n) const {
    return configuration == n.configuration;
  }
};

#endif