#include <vector>
using namespace std;
bool isValidSudoku(int i, int j, const vector<vector<char>> &board, char c) {
	for (int ind = 0; ind != 9; ++ind) {
		if (board[i][ind] == c) return false;
		if (board[ind][j] == c) return false;;
	}
	int m = i / 3, n = j / 3;
	for (int ii = m * 3; ii != m * 3 + 3; ++ii) 
		for (int jj = n * 3; jj != n * 3 + 3; ++jj) 
			if (board[ii][jj] == c) return false;
	return true;
}
bool solveSudoku(vector<vector<char>> &board) {
	for (int i = 0; i != 9; ++i) {
		for (int j = 0; j != 9; ++j) {
			if (board[i][j] != '.') continue;
			for (int k = 0; k != 9; ++k) {
				char tmp = '1' + k;
				if (isValidSudoku(i, j, board, tmp)) {
					board[i][j] = tmp;
					if (solveSudoku(board)) return true;
					board[i][j] = '.';
				}
			}
			return false;
		}
	}
	return true;
}
