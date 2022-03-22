#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int y;
	int x;
}position;

int main() {
	const position moveset[6] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };
	bool visited[200][200] = {};
	bool arrived = false;
	int n, movecount = 0;
	queue<position> q;
	position goal={};
	position start={};

	cin >> n;
	cin >> start.y >> start.x >> goal.y >> goal.x;
	visited[start.y][start.x] = true;
	q.push(start);
	while (!q.empty()) {
		if (arrived) break;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			position now = q.front();
			q.pop();
			if (now.x == goal.x && now.y == goal.y) {
				arrived = true;
				break;
			}
			for (int k = 0; k < 6; k++) {
				position newPos = { now.y + moveset[k].y,now.x + moveset[k].x };
				if (newPos.x >= 0 && newPos.y >= 0 && newPos.x < n && newPos.y < n) {
					if (visited[newPos.y][newPos.x]) continue;
					q.push(newPos);
					visited[newPos.y][newPos.x] = true;
				}
			}
		}
		movecount++;
	}
	cout << (arrived ? movecount-1 : -1);
}