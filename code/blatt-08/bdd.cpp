#include "bdd.hpp"

#include <fstream>
#include <vector>

Node *BDD::import_node(const Board &b) {
  Node *new_node = new Node(fresh_id++, b);
  nodes.push_back(new_node);

  // Überprüfen, ob dies der erste Knoten ist und den root-Zeiger aktualisieren
  if (root == nullptr) {
    root = new_node;
  }

  return new_node;
}

void BDD::connect(Node *parent, Node *children, bool if_true) {
  if (if_true) {
    parent->if_true = children;
  } else {
    parent->if_false = children;
  }
}

void BDD::connect_true(Node *parent, bool if_true) {
  if (if_true) {
    parent->if_true = true_node;
  } else {
    parent->if_false = true_node;
  }
}

void BDD::connect_false(Node *parent, bool if_true) {
  if (if_true) {
    parent->if_true = false_node;
  } else {
    parent->if_false = false_node;
  }
}

std::ostream &operator<<(std::ostream &stream, const BDD &bdd) {
  stream << "digraph BDD {\n";

  // Output nodes
  for (const auto *node : bdd.nodes) {
    stream << node->id << "[fontname=\"Comic Mono\",label= \""
           << node->configuration << "\"]\n";
  }

  // Output connections
  for (const auto *node : bdd.nodes) {
    if (node->if_true != nullptr && node->if_true != bdd.true_node) {
      stream << node->id << " -> " << node->if_true->id << ";\n";
    }
    if (node->if_false != nullptr && node->if_false != bdd.false_node) {
      stream << node->id << " -> " << node->if_false->id << "[style=dotted];\n";
    }
  }

  stream << "}\n";
  return stream;
}

void BDD::write_dot_file(std::string file_path) const {
  std::ofstream myfile;
  myfile.open(file_path);
  if (myfile.is_open()) {
    myfile << *this;
    myfile.close();
  }
}

int BDD::count_true_path() const {
  // TODO: Implement the function to count the number of paths leading to true
  return 0;
}
