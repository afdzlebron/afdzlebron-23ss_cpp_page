#include "nqueens.hpp"

int main() {
  NQueens queens(11);
  std::cout << queens.count_solutions();
}