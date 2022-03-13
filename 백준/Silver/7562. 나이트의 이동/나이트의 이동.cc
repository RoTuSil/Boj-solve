#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x;
	int y;
}Point;

int main() {

	const Point moveSets[8] =
	{ {1,2},{2,1},{2,-1},{1,-2},
	{-1,-2},{-2,-1},{-2,1},{-1,2} };

	int n,boardSize;
	cin >> n;
	for (int testcase = 0; testcase < n; testcase++) {
		bool visited[300][300] = {};
		queue<Point> q;
		Point pointTemp = {}, target = {};
		bool caseEnded = false;
		int turns = 0;
		cin >> boardSize;
		cin >> pointTemp.x >> pointTemp.y;
		cin >> target.x >> target.y;
		q.push(pointTemp);
		visited[pointTemp.x][pointTemp.y] = true;
		while (!q.empty()) {
			int qSize = q.size();
			if (caseEnded) break;
			for (int i = 0; i < qSize; i++) {
				Point now = q.front();
				q.pop();
				if (now.x == target.x && now.y == target.y) {
					cout << turns << endl;
					caseEnded = true;
					break;
				}
				int tempX;
				int tempY;
				for (int k = 0; k < 8; k++) {
					tempX = now.x + moveSets[k].x;
					tempY = now.y + moveSets[k].y;
					if (visited[tempX][tempY]) continue;
					if (tempX >= 0 && tempX < boardSize &&
						tempY >= 0 && tempY < boardSize) {
						pointTemp = { tempX,tempY };
						q.push(pointTemp);
						visited[tempX][tempY] = true;
					}
				}
			}
			turns++;
		}
	}
}
