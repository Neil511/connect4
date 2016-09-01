#include "board.hpp"

Board::Board() {
	for (int i = 0; i < 6; ++i) {
		std::vector<int> row;
		for (int j = 0; j < 7; ++j) {
			row.emplace_back(0);
		}
		board.emplace_back(row);
	}
}

bool Board::isValid(int column) {
	if (numFilled[column] == 7) return false;
	return true;
}

bool Board::makeMove(int column, int turn) {
	if(!isValid(column)) return false;

	board[numFilled[column]][column] = turn;
	numFilled[column]++;
	history.emplace_back(column);
	return true;
}

bool Board::checkWin(){ return true; }
