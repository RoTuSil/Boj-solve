#include <iostream>

using namespace std;

int area[100][100] = { 0 };
bool visited[100][100] = { false };

void clearbool() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visited[i][j] = false;
		}
	}
}

void checkNeighbor(int i, int j, int h, int size) {
	if (i < 0 || j < 0 || i >= size || j >= size) return;
	if (visited[i][j]) return;
	if (area[i][j] <= h) return;

	visited[i][j] = true;
	checkNeighbor(i + 1, j, h, size);
	checkNeighbor(i - 1, j, h, size);
	checkNeighbor(i, j + 1, h, size);
	checkNeighbor(i, j - 1, h, size);
}

int check(int size, int height) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (area[i][j] > height && !visited[i][j]) {
				checkNeighbor(i, j, height, size);
				count++;
			}
		}
	}
	return count;
}

int main() {
	int n, max = 0, maxarea = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
			if (area[i][j] > max)max = area[i][j];
		}
	}
	for (int h = 0; h < max; h++) {
		int c = check(n, h);
		clearbool();
		if (c > maxarea)maxarea = c;
	}
	cout << maxarea;
}