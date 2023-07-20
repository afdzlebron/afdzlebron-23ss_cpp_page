#include "bdd.hpp"

#include <fstream>
#include <vector>

Node *BDD::import_node(const Board &b) {
  /*TODO: Übungsblatt 8, Aufgabe 4*/
  // assert(false);
  return nullptr;
}

void BDD::connect(Node *parent, Node *children, bool if_true) {
  /*TODO: Übungsblatt 8, Aufgabe 4*/
  // assert(false);
}

void BDD::connect_true(Node *parent, bool if_true) {
  /*TODO: Übungsblatt 8, Aufgabe 4*/
  // assert(false);
}

void BDD::connect_false(Node *parent, bool if_true) {
  /*TODO: Übungsblatt 8, Aufgabe 4*/
  // assert(false);
}

std::ostream &operator<<(std::ostream &stream, const BDD &bdd) {
  /*TODO: Übungsblatt 8, Aufgabe 4*/
  // #assert(false);
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
  /*TODO: Übungsblatt 9, Aufgabe 7*/
  // assert(false);
  return 0;
}
