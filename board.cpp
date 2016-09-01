#include "board.hpp"

Board::Board() {
	for (int i = 0; i < 6; ++i) {
		vector<int> row;
		for (int j = 0; j < 7; ++i) {
			row.emplace_back(0);
		}
		board.emplace_back(row);
	}
}

bool Board::makeMove(int column, int turn) {
	if(!isValid(column)) return false;
	for (int i = 0; i < 7; ++i) {
		if (board[i][column] != 0) {
			board[i][column] = turn;
		}
	}
	numFilled[column]++;
}

bool Board::isValid(int column) {
	if (numFilled[column] == 7) return false;
	return true;
}