#include <iostream>
using namespace std;

const int moveset[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int forestSize;
int bamboo[500][500];
int maxPathLength[500][500];

int checkPath(int row, int col) {
	if (maxPathLength[row][col] != 0) {
		return maxPathLength[row][col];
	}
	int currentMax = 0;
	for (int k = 0; k < 4; k++) {
		int nr = row + moveset[k][0],
			nc = col + moveset[k][1];
		if (nr >= 0 && nc >= 0 && nr < forestSize && nc < forestSize) {
			if (bamboo[row][col] < bamboo[nr][nc]) {
				currentMax = max(currentMax, checkPath(nr, nc));
			}
		}
	}
	maxPathLength[row][col] = currentMax + 1;

	return maxPathLength[row][col];
}

int main() {
	cin >> forestSize;
	for (int i = 0; i < forestSize; i++) {
		for (int j = 0; j < forestSize; j++) {
			cin >> bamboo[i][j];
		}
	}
	int maxLength = 0;
	for (int i = 0; i < forestSize; i++) {
		for (int j = 0; j < forestSize; j++) {
			maxLength = max(checkPath(i, j), maxLength);
		}
	}
	cout << maxLength;
}