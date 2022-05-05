#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct Game {
	char board[3][3];
	int blankRow;
	int blankCol;
	void moveDown() {
		if (blankRow == 2) return;
		board[blankRow][blankCol] = board[blankRow + 1][blankCol];
		board[blankRow + 1][blankCol] = 0;
		blankRow++;
	}
	void moveUp() {
		if (blankRow == 0) return;
		board[blankRow][blankCol] = board[blankRow - 1][blankCol];
		board[blankRow - 1][blankCol] = 0;
		blankRow --;
	}
	void moveLeft() {
		if (blankCol == 0) return;
		board[blankRow][blankCol] = board[blankRow][blankCol - 1];
		board[blankRow][blankCol - 1] = 0;
		blankCol--;
	}
	void moveRight() {
		if (blankCol == 2) return;
		board[blankRow][blankCol] = board[blankRow][blankCol + 1];
		board[blankRow][blankCol + 1] = 0;
		blankCol++;
	}
	bool isSolved() {
		for (int i = 0; i < 8; i++) {
			if (board[i / 3][i % 3] != (i+1+'0')) return false;
		}
		return true;
	}
	string stringify() {
		string buffer="";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				buffer += board[i][j];
			}
		}
		return buffer;
	}
	bool operator==(const Game& target) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] != target.board[i][j]) return false;
			}
		}
		return true;
	}

};

int main() {
	Game game;
	set<string> visitedBoard;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int n;
			cin >> n;
			game.board[i][j] = n + '0';
			if (n == 0) {
				game.blankCol = j;
				game.blankRow = i;
			}
		}
	}
	int moveCount = 0;
	queue<Game> q;
	q.push(game);
	visitedBoard.insert(game.stringify());

	while (!q.empty()) {
		int size = q.size();
		for (int k = 0; k < size; k++) {
			Game now = q.front();
			q.pop();
			if (now.isSolved()) {
				cout << moveCount;
				return 0;
			}
			Game temp[4] = { now,now,now,now };
			temp[0].moveDown();
			temp[1].moveUp();
			temp[2].moveLeft();
			temp[3].moveRight();
			for (int i = 0; i < 4; i++) {
				if (!(temp[i] == now)) {
					if (visitedBoard.find(temp[i].stringify()) == visitedBoard.end()) {
						visitedBoard.insert(temp[i].stringify());
						q.push(temp[i]);
					}
				}
			}
		}
		moveCount++;
	}
	cout << -1;
}