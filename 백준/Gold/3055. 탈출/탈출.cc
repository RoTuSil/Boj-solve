#include <iostream>
#include <queue>
using namespace std;

struct Point { int x; int y; };
const Point moveset[4] = { {0,1},{1,0},{-1,0},{0,-1} };

int main() {
	Point end{};
	queue<Point> water;
	queue<Point> beaver;
	string board[50];
	bool visited[50][50]{};
	int r, c;
	int timePassed = 0;
	int escaped = false;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'S') {
				beaver.push({ j,i });
				visited[i][j] = true;
			}
			if (board[i][j] == '*') water.push({ j,i });
			if (board[i][j] == 'D') end = { j,i };
		}
 	}
	while (true) {
		if (beaver.empty()) break;
		int size = water.size();
		for (int i = 0; i < size; i++) {
			Point now = water.front();
			water.pop();
			for (int k = 0; k < 4; k++) {
				int nx = now.x + moveset[k].x,
					ny = now.y + moveset[k].y;
				if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
					if (board[ny][nx] == '.') {
						board[ny][nx] = '*';
						water.push({ nx,ny });
					}
				}
			}
		}
		size = beaver.size();
		for (int i = 0; i < size; i++) {
			Point now = beaver.front();
			beaver.pop();
			if (now.x == end.x && now.y == end.y) {
				escaped = true;
				break;
			}
			for (int k = 0; k < 4; k++) {
				int nx = now.x + moveset[k].x,
					ny = now.y + moveset[k].y;
				if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
					if ((board[ny][nx] == '.' || board[ny][nx] == 'D') && !visited[ny][nx]) {
						visited[ny][nx] = true;
						beaver.push({ nx,ny });
					}
				}
			}
		}
		if (escaped) break;
		timePassed++;
	}
	if (escaped) cout << timePassed;
	else cout << "KAKTUS";
}