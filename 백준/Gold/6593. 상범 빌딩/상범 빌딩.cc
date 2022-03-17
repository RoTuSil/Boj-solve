#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int z;
	int y;
	int x;
}Point;

const Point moveSet[6] = { {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };

int main() {
	int floor, row, column;
	Point pos = {}, end = {};
	while (true) {
		int timePassed = 0;
		string map[30][30];
		bool visited[30][30][30] = {};
		queue<Point> q;
		cin >> floor >> row >> column;
		if (floor == 0 && row == 0 && column == 0) break;
		for (int f = 0; f < floor; f++)
			for (int r = 0; r < row; r++)
				cin >> map[f][r];
		for (int f = 0; f < floor; f++) {
			for (int r = 0; r < row; r++) {
				for (int c = 0; c < column; c++) {
					if (map[f][r][c] == 'S') pos = { f,r,c };
					if (map[f][r][c] == 'E') end = { f,r,c };
				}
			}
		}
		q.push(pos);
		visited[pos.z][pos.y][pos.x]=true;
		bool escaped = false;
		while (!q.empty()) {
			if (escaped) break;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				Point now = q.front();
				q.pop();
				if (now.x == end.x && now.y == end.y && now.z == end.z) {
					escaped = true;
					break;
				}
				for (int k = 0; k < 6; k++) {
					int newX = now.x + moveSet[k].x;
					int newY = now.y + moveSet[k].y;
					int newZ = now.z + moveSet[k].z;
					if (newX >= 0 && newY >= 0 && newZ >= 0 && 
						newX < column && newY < row && newZ < floor) {
						if (!visited[newZ][newY][newX]&& map[newZ][newY][newX] != '#') {
							pos = { newZ,newY,newX };
							q.push(pos);
							visited[newZ][newY][newX] = true;
						}
					}
				}
			}
			timePassed++;
		}
		if (escaped) cout << "Escaped in " << --timePassed << " minute(s)." << endl;
		else cout << "Trapped!" << endl;
	}

}