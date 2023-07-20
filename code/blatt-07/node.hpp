#ifndef BLATT_BDD_NODE
#define BLATT_BDD_NODE

#include "board.hpp"

// Node in the BDD
//
// It contains 2 informations, the position and an id to help debugging
class Node {
 public:
  Node(int fresh_id, const Board &config)
      : id(fresh_id), configuration(config), if_true(nullptr) {}
  Node(int fresh_id, Board &&config)
      : id(fresh_id), configuration(config), if_true(nullptr) {}

 public:
  const int id;

  friend std::ostream &operator<<(std::ostream &stream, const Node &bdd);

  Board get_configuration() { return configuration; };

 private:
  Board configuration;

 public:
  Node *if_true;
  Node *if_false;
};

#endif