#include <iostream>
#include <queue>
using namespace std;

struct Point { int x; int y; };
const Point moveSet[4]{ {0,1},{1,0},{-1,0},{0,-1} };
string board[12];
bool isPopped;

void popPuyo(int x, int y) {
	bool visited[12][6]{};
	queue<Point> q;
	vector<Point> poppables;
	int sameCount = 1;
	q.push({ x,y });
	visited[y][x] = true;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = now.x + moveSet[i].x;
			ny = now.y + moveSet[i].y;
			if (nx >= 0 && ny >= 0 && nx < 6 && ny < 12) {
				if (board[ny][nx] == board[now.y][now.x] && !visited[ny][nx]) {
					sameCount++;
					q.push({ nx,ny });
					visited[ny][nx] = true;
				}
			}
		}
		poppables.push_back(now);
	}
	if (sameCount >= 4) {
		isPopped = true;
		for (Point p : poppables) {
			board[p.y][p.x] = '.';
		}
	}
}

void dropDown() {
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] != '.' && board[i + 1][j] == '.') {
				int k = i;
				char color = board[i][j];
				board[k][j] = '.';
				while (k < 11) {
					if (board[k + 1][j] == '.') k++;
					else break;
				}
				board[k][j] = color;
			}
		}
	}
}
int main() {
	board[0][0] = '.';
	int REN = 0;
	for (int i = 0; i < 12; i++) {
		cin >> board[i];
	}
	while (true) {
		isPopped = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.') {
					popPuyo(j,i);
				}
			}
		}
		if (!isPopped) break;
		dropDown();
		REN++;
	}
	cout << REN;
}