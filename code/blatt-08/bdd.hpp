#ifndef BLATT_BDD_BDD_HPP
#define BLATT_BDD_BDD_HPP

#include <iostream>
#include <string>
#include <vector>

#include "board.hpp"
#include "node.hpp"

class BDD {
 public:
  BDD()
      : fresh_id(3),
        true_node(&invalid_true_node),
        false_node(&invalid_false_node) {}

  Node *import_node(const Board &b);

  void connect(Node *parent, Node *children, bool if_true);
  void connect_true(Node *parent, bool if_true);
  void connect_false(Node *parent, bool if_true);

  friend std::ostream &operator<<(std::ostream &stream, const BDD &bdd);

  void write_dot_file(std::string file_path) const;

  int count_true_path() const;

  ~BDD() {
    for (Node *node : nodes) {
      delete node;
    }
  }
  Node *root = nullptr;

 private:
  int fresh_id;
  std::vector<Node *> nodes;

  Node invalid_true_node{1, Board()};
  Node invalid_false_node{2, Board()};
  Node *false_node;
  Node *true_node;
};

#endif  // BLATT_BDD_BDD_HPP
