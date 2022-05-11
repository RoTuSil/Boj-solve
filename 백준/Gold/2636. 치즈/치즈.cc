#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;
};

const Point moveSet[4] = { {0,1},{1,0},{-1,0},{0,-1} };
int cheeseBoard[100][100];
int height, width;
int cheeseCount = 0;

void updateAir() {
	bool visited[100][100]{};
	queue<Point> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		cheeseBoard[now.y][now.x] = -1;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + moveSet[i].x;
			int ny = now.y + moveSet[i].y;
			if (nx >= 0 && ny >= 0 && nx < width && ny < height) {
				if (!visited[ny][nx] && cheeseBoard[ny][nx] != 1) {
					q.push({ nx,ny });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

bool isCheeseTouchingAir(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + moveSet[i].x;
		int ny = y + moveSet[i].y;
		if (cheeseBoard[ny][nx] == -1) return true;
	}
	return false;
}

void meltCheese() {
	vector<Point> cheeseToMelt;
	for (int i = 1; i < height; i++) {
		for (int j = 1; j < width; j++) {
			if (cheeseBoard[i][j] == 1) {
				if (isCheeseTouchingAir(j, i))
					cheeseToMelt.push_back({ j,i });
			}
		}
	}
	for (int i = 0; i < cheeseToMelt.size();i++) {
		cheeseBoard[cheeseToMelt[i].y][cheeseToMelt[i].x] = -1;
		cheeseCount--;
	}
}

int main() {
	cin >> height >> width;
    
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> cheeseBoard[i][j];
			if (cheeseBoard[i][j] == 1) cheeseCount++;
		}
	}
	updateAir();
	int lastCheeseCount = 0;
	int timePassed = 0;
	while (cheeseCount) {
		lastCheeseCount = cheeseCount;
		updateAir();
		meltCheese();
		timePassed++;
	}
	cout << timePassed << "\n" << lastCheeseCount;
}