#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int y;
	int x;
}Point;
const Point moveset[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	int n, m, meetCount = 0;
	string map[600];
	bool visited[600][600] = {};
	queue<Point> q;
	Point temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'I') {
				temp = { i,j };
				q.push(temp);
			}
		}
	}
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Point now = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int tmpx = now.x + moveset[k].x;
				int tmpy = now.y + moveset[k].y;
				if (tmpx >= 0 && tmpy >= 0 && tmpx < m && tmpy < n) {
					if (visited[tmpy][tmpx] || map[tmpy][tmpx] == 'X') continue;
					if (map[tmpy][tmpx] == 'P') meetCount++;
					visited[tmpy][tmpx] = true;
					temp = { tmpy,tmpx };
					q.push(temp);
				}
			}
		}
	}
	if (!meetCount) cout << "TT";
	else cout << meetCount;
}