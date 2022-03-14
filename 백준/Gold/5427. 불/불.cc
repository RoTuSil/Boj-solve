#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int y;
	int x;
} Point;

const Point moveSet[4] = { {0,1},{1,0},{-1,0},{0,-1} };


int main() {
	int t;
	cin >> t;
	for (int tst = 0; tst < t; tst++) {
		int length = 0;
		int width, height;
		int timeEscape = 0;
		cin >> width >> height;
		string map[1000];
		queue<Point> manPos;
		queue<Point> firePos;

		bool** manVisited = new bool* [height];
		bool** fireVisited = new bool* [height];
		for (int i = 0; i < height; i++) {
			manVisited[i] = new bool[width];
			fireVisited[i] = new bool[width];
		}
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
                //idk why but if i dont do this every bool array resets to value of 205
				manVisited[h][w] = false;
				fireVisited[h][w] = false;
			}
		}
		Point temp{};
		for (int h = 0; h < height; h++)
			cin >> map[h];

		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				if (map[h][w] == '@') {
					temp = { h,w };
					manPos.push(temp);
					manVisited[h][w] = true;
				}
				if (map[h][w] == '*') {
					temp = { h,w };
					firePos.push(temp);
					fireVisited[h][w] = true;
				}
			}
		}
		bool escaped = false;
		while (!manPos.empty() || !firePos.empty()) {
			if (escaped) break;
			int manQsize = manPos.size();
			int fireQsize = firePos.size();
			for (int i = 0; i < manQsize; i++) {
				if (escaped) break;
				Point manNow = manPos.front();
				manPos.pop();
				if (fireVisited[manNow.y][manNow.x]) continue;
				//make exit stuff here
				if (manNow.x == 0 || manNow.x == width - 1 ||
					manNow.y == 0 || manNow.y == height - 1) {
					escaped = true; break;
				}
				//
				for (int k = 0; k < 4; k++) {
					int tmpX = manNow.x + moveSet[k].x;
					int tmpY = manNow.y + moveSet[k].y;
					if (tmpX >= 0 && tmpY >= 0 && tmpX < width && tmpY < height) {
						if (!manVisited[tmpY][tmpX] && !fireVisited[tmpY][tmpX] && map[tmpY][tmpX] == '.') {
							temp = { tmpY,tmpX };
							manPos.push(temp);
							manVisited[tmpY][tmpX] = true;
						}
					}
				}
			}
			for (int i = 0; i < fireQsize; i++) {
				Point fireNow = firePos.front();
				firePos.pop();				
				for (int k = 0; k < 4; k++) {
					int tmpX = fireNow.x + moveSet[k].x;
					int tmpY = fireNow.y + moveSet[k].y;
					if (tmpX >= 0 && tmpY >= 0 && tmpX < width && tmpY < height) {
						if (!fireVisited[tmpY][tmpX] && map[tmpY][tmpX] == '.') {
							temp = { tmpY,tmpX };
							firePos.push(temp);
							fireVisited[tmpY][tmpX] = true;
						}
					}
				}
			}
			timeEscape++;
		}
		if (escaped) cout << timeEscape << endl;
		else cout << "IMPOSSIBLE" << endl;
		for (int i = 0; i < height; i++) {
			delete[] manVisited[i];
			delete[] fireVisited[i];
		}
		delete[] manVisited;
		delete[] fireVisited;
	}
}
