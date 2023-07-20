#ifndef BLATT_BDD_BOARD
#define BLATT_BDD_BOARD

#include <gtest/gtest.h>

#include <cstdio>
#include <string>

// Representation of a configuration for our n-queens
// problem and iteration over all positions.
//
// Our class internally uses an array of int of a given size, where each int
// means:
//   - == 0 no queens in this column
//   - <0 no queen up to that position
//   - >0 the only queen is at that position.
//
// The board is already tailored toward our needs by disallowing 2 queens in
// this column. We also are using a fixed size.
//
// For each board, there are at most two successors: either the queen is at the
// next empty position (the column value was <= 0 and has now value > 0) or it
// is not (the column value was <=0 and is now decreased by 1).
class Board {
 public:
  Board() : size(0), board(nullptr) {}

  Board(int n) : size(n) {
    board = new int[size];
    for (int i = 0; i < size; ++i) board[i] = 0;
  }

  Board(const Board &pos) {
    size = pos.size;
    board = new int[size];
    for (int i = 0; i < size; ++i) board[i] = pos.board[i];
  }

  Board(Board &&pos) {
    size = pos.size;
    board = pos.board;
  }

  Board operator=(const Board &pos) {
    delete board;
    size = pos.size;
    board = new int[size];
    for (int i = 0; i < size; ++i) board[i] = pos.board[i];
    return *this;
  }

  ~Board() { delete[] board; }

  bool operator==(const Board &b) const {
    if (size != b.size) return false;
    for (int i = 0; i < size; ++i) {
      if (board[i] != b.board[i]) return false;
    }
    return true;
  }

  // checks if this position has a next position
  bool has_next(bool taken) const;

  // changes the current position to the next one
  // assuming that there is one
  void next(bool taken);

  // give a board as a string with '|' separating the cells with 'D' for queens
  // and when there is no queen, it prints '.' for positions where there is no
  // queen. For example |D|.|_|
  // |_|.|_|
  // |_| |_|
  // here the queen in the second column can only be at the very bottomx.
  friend std::ostream &operator<<(std::ostream &stream, const Board &board);

  // checks if the current board is compatible with the rules
  bool is_valid() const;

  // checks if the current board is compatible with the rules
  bool is_full() const;

 private:
  int size;
  int *board;
  FRIEND_TEST(BoardTest, nextTest);
  FRIEND_TEST(BoardTest, stringTest);
  FRIEND_TEST(BoardTest, validTest);
};

#endif
