#include <iostream>
using namespace std;

const int rookMove[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
const int knightMove[8][2] = { {2,1},{1,2},{-1,2},{2,-1},{-2,1},{1,-2},{-1,-2},{-2,-1} };
const int bishopMove[4][2] = { {1,1},{-1,1},{1,-1},{-1,-1} };
const int kingMove[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1} };

struct BOARD {
	char board[8][8]{};
	void FEN(string s) {
		int row = 0, col = 0;
		for (char c : s) {
			if ('0' < c && c < '9') {
				col += c - '0';
			} else if (c == '/') {
				row++;
				col = 0;
			} else {
				board[row][col] = c;
				col++;
			}
		}
	}
	int countNoAttack() {
		bool attackable[8][8]{};
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				int x = j;
				int y = i;
				if (board[i][j] != 0) attackable[i][j] = true;
				switch (board[i][j]) {
				case 'p':
					if (y + 1 < 8 && x + 1 < 8) {
						attackable[y + 1][x + 1] = true;
					}
					if (y + 1 < 8 && x - 1 >= 0) {
						attackable[y + 1][x - 1] = true;
					}
					break;
				case 'P':
					if (y - 1 >= 0 && x + 1 < 8) {
						attackable[y - 1][x + 1] = true;
					}
					if (y - 1 >= 0 && x - 1 >= 0) {
						attackable[y - 1][x - 1] = true;
					}
					break;
				case 'r':
				case 'R':
					for (int e = 0; e < 4; e++) {
						for (int k = 1; k < 8; k++) {
							int nx = x + rookMove[e][0] * k;
							int ny = y + rookMove[e][1] * k;
							if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
								attackable[ny][nx] = true;
								if (board[ny][nx] != 0) break;
							}
						}
					}
					break;
				case 'n':
				case 'N':
					for (int e = 0; e < 8; e++) {
						int nx = x + knightMove[e][0];
						int ny = y + knightMove[e][1];
						if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
							attackable[ny][nx] = true;
						}
					}
					break;
				case 'b':
				case 'B':
					for (int e = 0; e < 4; e++) {
						for (int k = 1; k < 8; k++) {
							int nx = x + bishopMove[e][0] * k;
							int ny = y + bishopMove[e][1] * k;
							if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
								attackable[ny][nx] = true;
								if (board[ny][nx] != 0) break;
							}
						}
					}
					break;
				case 'q':
				case 'Q':
					for (int e = 0; e < 8; e++) {
						for (int k = 1; k < 8; k++) {
							int nx = x + kingMove[e][0] * k;
							int ny = y + kingMove[e][1] * k;
							if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
								attackable[ny][nx] = true;
								if (board[ny][nx] != 0) break;
							}
						}
					}
					break;
				case 'k':
				case 'K':
					for (int k = 0; k < 8; k++) {
						int nx = x + kingMove[k][0];
						int ny = y + kingMove[k][1];
						if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
							attackable[ny][nx] = true;
						}
					}
					break;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (!attackable[i][j]) count++;
			}
		}
		return count;
	}
};

int main() {
	while (true) {
		string fen;
		cin >> fen;
		if (cin.eof()) break;
		BOARD b;
		b.FEN(fen);
		cout << b.countNoAttack() << "\n";
	}
}