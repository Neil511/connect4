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

bool Board::checkDirection(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
	int a = board.at(a1).at(a2);
	int b = board.at(b1).at(b2);
	int c = board.at(c1).at(c2);
	int d = board.at(d1).at(d2);

	return ((a == 1 || a == 2) && a == b && a == c && a == d);
}

bool Board::checkWin(){
	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < 7; ++j) {
			// Horizontal
			if (checkDirection(i, j, i, j+1, i, j+2, i, j+3)) return true;
			// Vertical
			if (checkDirection(i, j, i+1, j, i+2, j, i+3, j)) return true;
			// Diagonal Left
			if (checkDirection(i, j, i+1, j+1, i+2, j+2, i+3, j+3)) return true;
			// Diagonal Right
			if (checkDirection(i, j, i+1, j-1, i+2, j-2, i+3, j-3)) return true;
		}
	}
	return false;
}
