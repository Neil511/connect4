#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>

class Board {
	std::vector<std::vector<int>> board;
	std::vector<int> history;
	std::vector<int> numFilled;
public:
	Board();
	bool checkWin();
	bool makeMove(int turn, int column);
	bool isValid(int column);
  std::vector<std::vector<int>> getBoard();
  std::vector<int> getNumFilled();
  void printBoard();
  void printNumFilled();
private:
  bool checkDirection(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2);
};
#endif
