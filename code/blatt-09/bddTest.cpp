#include <gtest/gtest.h>

#include <fstream>
#include <iostream>

#include "bdd.hpp"

// In this test, we construct a simple BDD with boards of length 4 and we write
// the corresponding graph to a file.
TEST(BDDTest, basicTest) {
  Board a(4);
  Board b(4);
  BDD bdd;

  Node *a1 = bdd.import_node(a);

  ASSERT_TRUE(a.has_next(true));
  a.next(true);
  Node *a2 = bdd.import_node(a);

  ASSERT_TRUE(b.has_next(false));
  b.next(false);

  Node *b2 = bdd.import_node(b);
  bdd.connect(a1, a2, true);
  bdd.connect(a1, b2, false);
  ASSERT_EQ(a1->if_true, a2);
  ASSERT_EQ(a1->if_false, b2);
  ASSERT_EQ(bdd.root, a1);

  bdd.connect_true(a2, true);
  bdd.connect_true(a2, false);

  bdd.connect_true(b2, true);
  bdd.connect_false(b2, false);

  ASSERT_EQ(bdd.count_true_path(), 3);

  std::ofstream myfile;
  myfile.open("small_test_bdd.txt");
  if (myfile.is_open()) {
    myfile << bdd;
    myfile.close();
  }
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
