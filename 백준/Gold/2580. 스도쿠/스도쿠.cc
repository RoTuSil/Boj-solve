#include <iostream>
#include <vector>
using namespace std;

struct p {
	int r;
	int c;
};

int board[9][9]{};
int blankCount = 0;
vector<p> v;

bool checkValid(int r, int c, int val) {
	for (int i = 0; i < 9; i++) {
		if ( r != i && board[i][c] == val) return false;
		if (c != i && board[r][i] == val) return false;
	}
	int nr = (r / 3) * 3;
	int nc = (c / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[nr + i][nc + j] == val) return false;
		}
	}
	return true;
}
bool found = false;;
void solveSudoku(int d) {
	if (d == blankCount) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		found = true;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (checkValid(v[d].r, v[d].c, i)) {
			board[v[d].r][v[d].c] = i;
			solveSudoku(d + 1);
			if (found) return;
			board[v[d].r][v[d].c] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) v.push_back({ i,j });
		}
	}
	blankCount = v.size();
	solveSudoku(0);
}
