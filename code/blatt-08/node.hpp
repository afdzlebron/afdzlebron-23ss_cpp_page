#ifndef BLATT_BDD_NODE
#define BLATT_BDD_NODE

#include <iostream>

#include "board.hpp"

// Node in the BDD
//
// It contains 2 informations, the position and an id to help debugging
class Node {
 public:
  Node(int fresh_id, const Board &config)
      : id(fresh_id),
        configuration(config),
        if_true(nullptr),
        if_false(nullptr) {}

  friend std::ostream &operator<<(std::ostream &stream, const Node &bdd);

  const Board &get_configuration() const { return configuration; }

  Node *if_true;
  Node *if_false;

  const int id;

  Board configuration;
};

#endif