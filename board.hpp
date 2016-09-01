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
	bool makeMove(int column, int turn);
	bool isValid(int column);
};
#endif
