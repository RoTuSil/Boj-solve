#include <iostream>
using namespace std;

string image[64] = {};

void quadTree(int size, int startRow, int startCol) {
	char firstelement = image[startRow][startCol];
	if (size == 1) {
		cout << image[startRow][startCol];
		return;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (image[startRow + i][startCol + j] != firstelement) {
				cout << "(";
				int half = size / 2;
				quadTree(half, startRow, startCol);
				quadTree(half, startRow, startCol + half);
				quadTree(half, startRow + half, startCol);
				quadTree(half, startRow + half, startCol + half);
				cout << ")";
				return;
			}
		}
	}
	cout << firstelement;
}

int main() {
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> image[i];
	}
	quadTree(size, 0, 0);
}