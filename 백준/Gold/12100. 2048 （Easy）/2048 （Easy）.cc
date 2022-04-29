#include <iostream>
using namespace std;

int boardSize;
int maxValue = 0;

struct Game {
	int board[20][20];
	
	void moveLeft() {
		bool merged[20][20]{};
		for (int i = 0; i < boardSize; i++) {
			for (int j = 1; j < boardSize; j++) {
				if (board[i][j] == 0) continue;
				int x = j;
				while (true) {
					if (x == 0) break;
					if (board[i][x - 1] != 0) {
						if (board[i][x] == board[i][x - 1]) {
							if (merged[i][x - 1]) break;
							board[i][x - 1] *= 2;
							board[i][x] = 0;
							merged[i][x - 1] = true;
						}
						break;
					}
					board[i][x - 1] = board[i][x];
					board[i][x] = 0;
					x--;
				}
			}
		}
	}
	void moveRight() {
		bool merged[20][20]{};
		for (int i = 0; i < boardSize; i++) {
			for (int j = boardSize - 2; j >= 0; j--) {
				if (board[i][j] == 0) continue;
				int x = j;
				while (true) {
					if (x == boardSize - 1) break;
					if (board[i][x + 1] != 0) {
						if (board[i][x] == board[i][x + 1]) {
							if (merged[i][x + 1]) break;;
							board[i][x + 1] *= 2;
							board[i][x] = 0;
							merged[i][x + 1] = true;
						}
						break;
					}
					board[i][x + 1] = board[i][x];
					board[i][x] = 0;
					x++;
				}
			}
		}
	}
	void moveUp() {
		bool merged[20][20]{};
		for (int i = 1; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (board[i][j] == 0) continue;
				int y = i;
				while (true) {
					if (y == 0) break;
					if (board[y - 1][j] != 0) {
						if (board[y - 1][j] == board[y][j]) {
							if (merged[y - 1][j]) break;
							board[y - 1][j] *= 2;
							board[y][j] = 0;
							merged[y - 1][j] = true;
						}
						break;
					}
					board[y - 1][j] = board[y][j];
					board[y][j] = 0;
					y--;
				}
			}
		}
	}
	void moveDown() {
		bool merged[20][20]{};
		for (int i = boardSize - 2; i >= 0; i--) {
			for (int j = 0; j < boardSize; j++) {
				if (board[i][j] == 0) continue;
				int y = i;
				while (true) {
					if (y == boardSize - 1) break;
					if (board[y + 1][j] != 0) {
						if (board[y + 1][j] == board[y][j]) {
							if (merged[y + 1][j]) break;
							board[y + 1][j] *= 2;
							board[y][j] = 0;
							merged[y + 1][j] = true;
						}
						break;
					}
					board[y + 1][j] = board[y][j];
					board[y][j] = 0;
					y++;
				}
			}
		}
	}

	int getMaxValue() {
		int maximum = 0;
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				maximum = max(maximum, board[i][j]);
			}
		}
		return maximum;
	}
};

void moveBoard(int depth,Game g) {
	if (depth == 5) {
		maxValue = max(maxValue, g.getMaxValue());
		return;
	}
	Game temp = g;
	temp.moveLeft();
	moveBoard(depth + 1, temp);
	temp = g;
	temp.moveRight();
	moveBoard(depth + 1, temp);
	temp = g;
	temp.moveUp();
	moveBoard(depth + 1, temp);
	temp = g;
	temp.moveDown();
	moveBoard(depth + 1, temp);
}

int main() {
	Game game;
	cin >> boardSize;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cin >> game.board[i][j];
		}
 	}
	moveBoard(0, game);
	cout << maxValue;
}