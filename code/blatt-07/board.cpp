#include "board.hpp"

#include <assert.h>

#include <string>

bool Board::has_next(bool taken) const {
  int position_to_change = -1;
  for (int i = 0; i < size; ++i) {
    if (board[i] <= 0) {
      position_to_change = i;
      break;
    }
  }

  if (position_to_change == -1) return false;

  const int value = board[position_to_change];

  if (!taken && size == -value + 1) return false;

  return true;
}

void Board::next(bool taken) {
  int position_to_change = -1;
  for (int i = 0; i < size; ++i) {
    if (board[i] <= 0) {
      position_to_change = i;
      break;
    }
  }

  assert(position_to_change != -1);

  const int value = board[position_to_change];

  assert(taken || size != value - 1);

  if (taken)
    board[position_to_change] = -value + 1;
  else
    board[position_to_change] -= 1;
}

std::ostream &operator<<(std::ostream &stream, const Board &board) {
  for (int line = 0; line < board.size; ++line) {
    stream << "|";
    for (int row = 0; row < board.size; ++row) {
      if (board.board[row] - 1 == line)
        stream << "d";
      else if (board.board[row] < 0 && line <= -board.board[row] - 1)
        stream << ".";
      else
        stream << " ";
      stream << "|";
    }
    stream << "\n";
  }
  return stream;
}

// Checks if a position is valid: two queens are (i) on the same row if they
// have the position and (ii) are on the same diagonal if the distance is the
// same as the row distance.
bool Board::is_valid() const {
  for (int i = 0; i < size; ++i) {
    if (board[i] > 0) {
      for (int j = i + 1; j < size; ++j) {
        if (board[j] > 0) {
          if (board[i] == board[j]) return false;
          if (abs(board[i] - board[j]) == abs(i - j)) return false;
        }
      }
    }
  }
  return true;
}

bool Board::is_full() const {
  for (int i = 0; i < size; ++i) {
    if (board[i] <= 0) return false;
  }
  return true;
}