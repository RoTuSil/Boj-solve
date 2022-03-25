#include <iostream>
using namespace std;

typedef struct {
	int y;
	int x;
}Position;

const Position directions[4] = { {-1,0},{0,1},{1,0},{0,-1} };

typedef struct Cleaner{
	Position pos;
	int dir;

	void turnLeft() {
		dir--;
		if (dir == -1) dir = 3;
	}
	void moveForward() {
		pos.x += directions[dir].x;
		pos.y += directions[dir].y;
	}
	void moveBack() {
		pos.x -= directions[dir].x;
		pos.y -= directions[dir].y;
	}

	Position getBackPos() {
		return { pos.y - directions[dir].y, pos.x - directions[dir].x };
	}
	
	Position getLeftPos() {
		int tempDir = dir - 1;
		if (tempDir == -1) tempDir = 3;
		return { pos.y + directions[tempDir].y, pos.x + directions[tempDir].x };
	}

};

int main() {
	int r, c, dirIndex, cleanedSpotCount = 0;
	bool map[50][50] = {};
	bool cleaned[50][50] = {};
	Cleaner cleaner;
	cin >> r >> c;
	cin >> cleaner.pos.y >> cleaner.pos.x >> dirIndex;
	cleaner.dir = dirIndex;
	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			cin >> map[row][col];
		}
	}
	while (true) {
		cleanedSpotCount++;
		cleaned[cleaner.pos.y][cleaner.pos.x] = true;
		bool continueState = false;
		for (int i = 0; i < 4; i++) {
			Position leftPos = cleaner.getLeftPos();
			if (!cleaned[leftPos.y][leftPos.x] && !map[leftPos.y][leftPos.x]) {
				cleaner.turnLeft();
				cleaner.moveForward();
				continueState = true;
				break;
			}
			cleaner.turnLeft();
		}
		if (continueState) continue;
		Position backPos = cleaner.getBackPos();
		if (map[backPos.y][backPos.x]) break;
		cleaner.moveBack();
		cleanedSpotCount--;
	}
	cout << cleanedSpotCount;
}