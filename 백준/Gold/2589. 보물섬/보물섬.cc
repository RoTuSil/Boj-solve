#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
} Point;
int main() {
	int h, w, maxlength = 0,length;
	cin >> h >> w;
	Point moveSet[4] = {{1,0},{0,1},{-1,0},{0,-1}};
	string map[50];
	queue<Point> q;
	for (int i = 0; i < h; i++)
		cin >> map[i];
	for (int height = 0; height < h; height++) {
		for (int width = 0; width < w; width++) {
			length = -1;
			bool visited[50][50] = {};
			if (map[height][width] == 'W') continue;
			Point temp = { width,height };
			visited[height][width] = true;
			q.push(temp);
			while (!q.empty()) {
				int size = q.size();
				for (int i = 0; i < size; i++) {
					Point now = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int tmpX = now.x + moveSet[k].x;
						int tmpY = now.y + moveSet[k].y;
						if (tmpX >= 0 && tmpX < w && tmpY >= 0 && tmpY < h) {
							if (map[tmpY][tmpX] == 'L' && !visited[tmpY][tmpX] ) {
								temp = { tmpX,tmpY };
								q.push(temp);
								visited[tmpY][tmpX] = true;
							}
						}
					}
				}
				length++;
			}
			maxlength = max(maxlength, length);
		}
	}
	cout << maxlength;
}