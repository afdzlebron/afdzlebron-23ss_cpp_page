#include "nqueens.hpp"

int main() {
  NQueens queens(4);
  std::cout << queens.count_solutions();
}
