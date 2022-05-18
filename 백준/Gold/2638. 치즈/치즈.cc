#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;
};

const Point moveSet[4] = { {0,1},{1,0},{-1,0},{0,-1} };

int cheeseBoard[100][100];
int width, height;
int timePassed;

int main() {
	cin >> height >> width; 
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> cheeseBoard[i][j];
		}
	}

	while (true) {
		queue<Point> q;
		vector<Point> cheeseToMelt;
		bool visited[100][100]{};
		int airTouchCount[100][100]{};

		q.push({ 0,0 });
		visited[0][0] = true;
		while (!q.empty()) {
			Point now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = now.y + moveSet[i].y;
				int nc = now.x + moveSet[i].x;
				if (nr >= 0 && nc >= 0 && nr < height && nc < width) {
					if (cheeseBoard[nr][nc] == 1) {
						airTouchCount[nr][nc]++;
						if (airTouchCount[nr][nc] == 2) {
							cheeseToMelt.push_back({ nc, nr });
						}
					}
					if (!visited[nr][nc]) {
						if (cheeseBoard[nr][nc] == 0) {
							q.push({ nc,nr });
						}
						visited[nr][nc] = true;
					}
				}
			}
		}
		if (cheeseToMelt.empty()) break;

		for (Point i : cheeseToMelt) {
			cheeseBoard[i.y][i.x] = 0;
		}
		timePassed++;
	}
	cout << timePassed;
}