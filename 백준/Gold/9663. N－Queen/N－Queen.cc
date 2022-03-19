#include <iostream>
using namespace std;

bool board[14][14];
bool placed[14];
int countValid = 0;
int n;
//doesn't need to check all 8 directions,check only left-up and right-up
const int moveset[2][2] = { {-1,1},{-1,-1} };


bool check(int r, int c) {
	if (placed[c]) return true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			int newR = r + moveset[j][0] * i;
			int newC = c + moveset[j][1] * i;
			if (newR >= 0 && newC >= 0 && newR < n && newC < n) {
				if (board[newR][newC]) return true;
			}
		}
	}
	return false;
}

void nQueen(int d) {
	if (d == n) {
		countValid++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check(d, i)) {
			board[d][i] = true;
			placed[i] = true;
			nQueen(d + 1);
			board[d][i] = false;
			placed[i] = false;
		}
	}
}

int main() {
	cin >> n;
	nQueen(0);
	cout << countValid;
}