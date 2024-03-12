#include <iostream>

using namespace std;

int main() {
	const int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
	int row, column, time;
	int room[50][50]{};
	
	int upperY, lowerY;
	upperY = lowerY = -1;

	cin >> row >> column >> time;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				if (upperY == -1) {
					upperY = i;
				}
				else {
					lowerY = i;
				}
			}
		}
	}

	for (int t = 0; t < time; t++) {
		//diffusion
		int calculated[50][50]{};
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < column; c++) {
				if (room[r][c] > 0) {
					int neighborCount = 0;
					for (int k = 0; k < 4; k++) {
						int newR = r + dir[k][0];
						int newC = c + dir[k][1];
						if (newR >= 0 && newC >= 0 && newR < row && newC < column) {
							if(room[newR][newC] != -1)
								neighborCount++;
						}
					}
					for (int k = 0; k < 4; k++) {
						int newR = r + dir[k][0];
						int newC = c + dir[k][1];
						if (newR >= 0 && newC >= 0 && newR < row && newC < column) {
							if (room[newR][newC] != -1) {
								calculated[newR][newC] += room[r][c] / 5;
							}
						}
					}
					calculated[r][c] -= (room[r][c] / 5) * neighborCount;
				}
			}
		}
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < column; c++) {
				room[r][c] += calculated[r][c];
			}
		}
		//air purifier action

		//upper purifier
		for (int i = upperY-1; i >=1; i--) {
			room[i][0] = room[i - 1][0];
			room[i - 1][0] = 0;
		}
		for (int i = 0; i < column - 1; i++) {
			room[0][i] = room[0][i + 1];
			room[0][i + 1] = 0;
		}
		for (int i = 0; i < upperY; i++) {
			room[i][column-1] = room[i + 1][column-1];
			room[i + 1][column - 1] = 0;
		}
		for (int i = column - 1; i >= 2; i--) {
			room[upperY][i] = room[upperY][i - 1];
			room[upperY][i - 1] = 0;
		}

		//lower purifier
		
		for (int i = lowerY+1; i < row - 1; i++) {
			room[i][0] = room[i + 1][0];
			room[i + 1][0] = 0;
		}
		for (int i = 0; i < column - 1; i++) {
			room[row-1][i] = room[row-1][i + 1];
			room[row - 1][i + 1] = 0;
		}
		for (int i = row - 1; i >lowerY; i--) {
			room[i][column - 1] = room[i -1][column - 1];
			room[i - 1][column - 1] = 0;
		}
		for (int i = column - 1; i > 1; i--) {
			room[lowerY][i] = room[lowerY][i - 1];
			room[lowerY][i - 1] = 0;
		}
	}
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (room[i][j] != -1) sum += room[i][j];
		}
	}
	cout << sum;

}