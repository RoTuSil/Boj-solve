#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int y;
	int x;
}Position;

const Position moveset[4] = { {0,1},{1,0},{-1,0},{0,-1} };

int map[8][8] = {};
int n, m;
vector<Position> virus;
vector<Position> emptyArea;

int bfs() {
	int safeArea = emptyArea.size();
	queue<Position> q;
	bool visited[8][8] = {};
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		visited[virus[i].y][virus[i].x] = true;
	}
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Position now = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				Position newPos = { now.y + moveset[k].y,now.x + moveset[k].x };
				if (newPos.x >= 0 && newPos.y >= 0 && newPos.x < m && newPos.y < n) {
					if (visited[newPos.y][newPos.x]) continue;
					if (map[newPos.y][newPos.x] == 1) continue;
					visited[newPos.y][newPos.x] = true;
					q.push(newPos);
					safeArea--;
				}
			}
		}

	}
	return safeArea - 3;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) emptyArea.push_back({ i,j });
			else if (map[i][j] == 2) virus.push_back({ i,j });
		}
	}
	int maxSafeArea = 0;
	int size = emptyArea.size();
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			for (int k = j + 1; k < size; k++) {
				map[emptyArea[i].y][emptyArea[i].x] = 1;
				map[emptyArea[j].y][emptyArea[j].x] = 1;
				map[emptyArea[k].y][emptyArea[k].x] = 1;
				maxSafeArea = max(maxSafeArea, bfs());
				map[emptyArea[i].y][emptyArea[i].x] = 0;
				map[emptyArea[j].y][emptyArea[j].x] = 0;
				map[emptyArea[k].y][emptyArea[k].x] = 0;
			}
		}
	}
	cout << maxSafeArea;
}