#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int r;
	int c;
};

Point neighbor[4] = { {0,1},{1,0},{-1,0},{0,-1} };
vector<Point> ices;
int heightMap[300][300];
int row, column;
int iceCount;

int checkNearbyWater(int r, int c) {
	int water = 0;
	for (int i = 0; i < 4; i++) {
		if (r + neighbor[i].r < row && r + neighbor[i].r >= 0 &&
			c + neighbor[i].c < column && c + neighbor[i].c >= 0) {
			if (heightMap[r + neighbor[i].r][c + neighbor[i].c] == 0) water++;
		}
	}
	return water;
}

bool meltIce() {
	int l = ices.size();
	bool isThereIce = false;
	vector<pair<Point, int>> meltValue;
	for (int i = 0; i < l; i++) {
		int r = ices[i].r;
		int c = ices[i].c;
		if (!heightMap[r][c]) continue;
		isThereIce = true;
		meltValue.push_back({ {r,c},checkNearbyWater(r, c) });
	}
	for (int i = 0; i < meltValue.size(); i++) {
		int r = meltValue[i].first.r;
		int c = meltValue[i].first.c;
		heightMap[r][c] -= meltValue[i].second;
		if (heightMap[r][c] <= 0) {
			iceCount--;
			heightMap[r][c] = 0;
		}
	}
	return isThereIce;
}

int countMTE() {
	bool visited[300][300]{};
	queue<Point> q;
	int MTE = 0;
	int i, j;
	int k = 0;
	while (true) {
		i = ices[k].r;
		j = ices[k].c;
		if (heightMap[i][j]) break;
		k++;
		if (k > ices.size()) return 0;
	}
	q.push({ i,j });
	visited[i][j] = true;
	MTE++;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			Point newP = { now.r + neighbor[k].r,now.c + neighbor[k].c };
			if (newP.r < row && newP.r >= 0 &&
				newP.c < column && newP.c >= 0) {
				if (!visited[newP.r][newP.c] && heightMap[newP.r][newP.c] != 0) {
					q.push(newP);
					visited[newP.r][newP.c] = true;
					MTE++;
				}
			}
		}
	}
	if (iceCount - MTE == 0) return 0;
	else return 2;
}

int main() {
	int yearPassed = 0;
	cin >> row >> column;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> heightMap[i][j];
			if (heightMap[i][j] != 0) ices.push_back({ i,j });
		}
	}
	iceCount = ices.size();
	while (true) {
		if (countMTE() >= 2) break;
		if (!meltIce()) {
			cout << "0";
			return 0;
		}
		yearPassed++;
	}
	cout << yearPassed;
}