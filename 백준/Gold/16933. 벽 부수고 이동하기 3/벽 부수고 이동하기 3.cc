#include <iostream>
#include <queue>
using namespace std;


struct Point { int x, y, z;};


const Point _set[4] = { {0,1},{1,0},{-1,0},{0,-1} };

string map[1000];

queue<Point> q;

bool visited[1000][1000][11];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	q.push({ 0,0,0 });
	visited[0][0][0] = true;
	int timepassed = 0;


	while (!q.empty()) {

		timepassed++;
		int size = q.size();

		for (int i = 0; i < size; i++) {
			Point front = q.front();

			if (front.x + 1 == m && front.y + 1 == n) {
				cout << timepassed << endl;
				return 0;
			}


			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = front.x + _set[j].x;
				int ny = front.y + _set[j].y;

				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

				if (map[ny][nx] == '0') {
					if (!visited[ny][nx][front.z]) {
						q.push({ nx,ny,front.z });
						visited[ny][nx][front.z] = true;
					}
				}
				else if (map[ny][nx] == '1') {
					if (timepassed % 2 == 1) {
						if (!visited[ny][nx][front.z + 1]) {
							if (front.z < k) {
								q.push({ nx,ny,front.z + 1 });
								visited[ny][nx][front.z + 1] = true;
							}
						}
					}
					else {
						q.push({ front.x,front.y,front.z});
						visited[front.y][front.x][front.z] = true;
					}
				}
				
				
			}
		}
	}
	cout << "-1";
}