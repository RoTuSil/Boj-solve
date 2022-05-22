#include <iostream>
#include <queue>
using namespace std;

struct Position {
	int y;
	int x;
	int wallRemoved;
};
const Position moveset[8]{ {0,1},{1,0},{-1,0},{0,-1} };
bool visited[1000][1000][10];

int main() {
	int row, col, removeCount, length = 1;
	string map[1000];
	queue<Position> q;
	cin >> row >> col >> removeCount;
	for (int i = 0; i < row; i++)
		cin >> map[i];
	q.push({ 0,0,0 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Position now = q.front();
			q.pop();
			if (now.x == col - 1 && now.y == row - 1) {
				cout << length;
				return 0;
			}
			for (int k = 0; k < 4; k++) {
				Position newPos = { now.y + moveset[k].y,now.x + moveset[k].x ,now.wallRemoved };
				if (newPos.x >= 0 && newPos.y >= 0 && newPos.x < col && newPos.y < row) {
					if (map[newPos.y][newPos.x] == '0' && !visited[newPos.y][newPos.x][newPos.wallRemoved]) {
						q.push(newPos);
						visited[newPos.y][newPos.x][newPos.wallRemoved] = true;
					} else if (map[newPos.y][newPos.x] == '1' && newPos.wallRemoved < removeCount &&
						!visited[newPos.y][newPos.x][newPos.wallRemoved]) {
							newPos.wallRemoved++;
							q.push(newPos);
							visited[newPos.y][newPos.x][newPos.wallRemoved] = true;
					}
				}
			}
		}
		length++;
	}
	cout << -1;
}