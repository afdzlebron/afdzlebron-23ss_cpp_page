#include "bdd.hpp"

#include <vector>

#include "stack.hpp"

Node *BDD::import_node(const Board &b) {
  Board a = b;

  Node *n = new Node(++fresh_id, b);

  nodes.push_back(n);
  n->if_false = nullptr;
  n->if_true = nullptr;

  if (!root) root = n;
  return n;
}

void BDD::connect(Node *parent, Node *children, bool if_true) {
  if (if_true)
    parent->if_true = children;
  else
    parent->if_false = children;
}

void BDD::connect_true(Node *parent, bool if_true) {
  if (if_true)
    parent->if_true = true_node;
  else
    parent->if_false = true_node;
}

void BDD::connect_false(Node *parent, bool if_true) {
  if (if_true)
    parent->if_true = false_node;
  else
    parent->if_false = false_node;
}

int BDD::count_true_path() const {
  int count = 0;

  if (root == nullptr) return count;

  std::vector<Node *> stack;
  stack.push_back(root);

  while (!stack.empty()) {
    Node *current = stack.back();
    stack.pop_back();

    if (current == true_node) {
      count++;
    } else if (current != false_node) {
      stack.push_back(current->if_true);
      stack.push_back(current->if_false);
    }
  }

  return count;
}

std::ostream &operator<<(std::ostream &stream, const BDD &bdd) {
  std::vector<Node *> queue;
  if (bdd.root) queue.push_back(bdd.root);
  const std::string true_name("true");
  const std::string false_name("false");

  stream << "digraph BDD\n {";

  for (const auto &node : bdd.nodes) {
    stream << node->id << "[fontname=\"Comic Mono\",label= \"" << *node
           << "\"]\n";
  }

  for (const auto &b : bdd.nodes) {
    // connect the current node to its true descendant
    stream << b->id << " -> ";
    if (b->if_true != bdd.true_node && b->if_true != bdd.false_node)
      stream << b->if_true->id << ";\n";
    else
      stream << (b->if_true == bdd.true_node ? true_name : false_name) << ";\n";

    // connect the current node to its false descendant
    stream << b->id << " -> ";
    if (b->if_false != bdd.true_node && b->if_false != bdd.false_node)
      stream << b->if_false->id;
    else
      stream << (b->if_false == bdd.true_node ? true_name : false_name);
    stream << "[style=dotted]"
           << ";\n";
  }

  stream << "}";

  return stream;
}
