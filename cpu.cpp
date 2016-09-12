#include "cpu.hpp"
#include <stdexcept>
#include "board.hpp"

CPU::CPU(int playerNumber, std::shared_ptr<Board> board, int level): Player(playerNumber, board), level(level) {}

bool checkDirection(std::vector<std::vector<int>> pieces, int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
  try {
    int a = pieces.at(a1).at(a2);
    int b = pieces.at(b1).at(b2);
    int c = pieces.at(c1).at(c2);
    int d = pieces.at(d1).at(d2);
    // since CPU will always be player 2
    return ((a == 1) && a == b && a == c && a == d);
  }
  catch (const std::out_of_range& e) {
    return false;
  }
}

int CPU::getMove() {
  std::vector<std::vector<int>> pieces = board->getBoard();
  std::vector<int> numFilled = board->getNumFilled();
  // make sure the next move doesn't give them a win
  if(level >= 4) {
    // Pruning
    // TODO
  }

  if(level >= 3) {
    // block opponent's offensive move if one exists
    for(int i = 0; i < 7; ++i) {
      // for each column
      int nextSpot = numFilled.at(i);
      // next possible placed is i + 1
      // remember this is inverse of rows
      // 5 placed means next row is 0 not 6
      pieces.at(nextSpot + 1).at(i) = 1;
      for(int j = nextSpot + 1; j < 6; ++j) {
        for(int k = i; k < 7; ++k) {
          // check each direction for 3 in a row
          // Horizontal
          if (checkDirection(pieces, j, k, j, k+1, j, k+2, j, k+3)) return i;
          // Vertical
          if (checkDirection(pieces, j, k, j+1, k, j+2, k, j+3, k)) return i;
          // Diagonal Left
          if (checkDirection(pieces, j, k, j+1, k+1, j+2, k+2, j+3, k+3)) return i;
          // Diagonal Right
          if (checkDirection(pieces, j, k, j+1, k-1, j+2, k-2, j+3, k-3)) return i;
        }
      }
    }
  }

  if(level >= 2) {
    // Aggresive play
    // TODO
    return 0;
  }

  if(level >= 1) {
    // TODO
    // Do random number generation between cols and see if valid
    return 0;
  }
  return 0;
}
