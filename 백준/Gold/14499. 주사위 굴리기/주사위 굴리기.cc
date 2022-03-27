#include <iostream>
using namespace std;

int map[20][20];
int width, height;

struct Dice {
	int x;
	int y;

	/*		2
	*	  4	1 3
	*		5
	*		6	*/
	int value[6] = {};


	bool isMoveable(int i, int j) {
		return (i >= 0 && j >= 0 && i < height&& j < width);
	}
	void copyMap() {
		if (map[y][x] == 0) {
			map[y][x] = value[5];
		} else {
			value[5] = map[y][x];
			map[y][x] = 0;
		}
		cout << value[0] << "\n";
	}
	void rotateEast() {
		int v[6];
		v[0] = value[3];
		v[1] = value[1];
		v[2] = value[0];
		v[3] = value[5];
		v[4] = value[4];
		v[5] = value[2];
		for (int i = 0; i < 6; i++)
			value[i] = v[i];
		copyMap();
	}
	void rotateWest() {
		int v[6];
		v[0] = value[2];
		v[1] = value[1];
		v[2] = value[5];
		v[3] = value[0];
		v[4] = value[4];
		v[5] = value[3];
		for (int i = 0; i < 6; i++)
			value[i] = v[i];
		copyMap();
	}
	void rotateNorth() {
		int v[6];
		v[0] = value[4];
		v[1] = value[0];
		v[2] = value[2];
		v[3] = value[3];
		v[4] = value[5];
		v[5] = value[1];
		for (int i = 0; i < 6; i++)
			value[i] = v[i];
		copyMap();
	}
	void rotateSouth() {
		int v[6];
		v[0] = value[1];
		v[1] = value[5];
		v[2] = value[2];
		v[3] = value[3];
		v[4] = value[0];
		v[5] = value[4];
		for (int i = 0; i < 6; i++)
			value[i] = v[i];
		copyMap();
	}
};

int main() {
	Dice dice;
	int orderNum;
	int order[1000]{};
	cin >> height >> width >> dice.y >> dice.x >> orderNum;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < orderNum; i++) {
		cin >> order[i];
		switch (order[i]) {
		case 1:
			if (dice.isMoveable(dice.y, dice.x + 1)) {
				dice.x++;
				dice.rotateEast();
			}
			break;
		case 2:
			if (dice.isMoveable(dice.y, dice.x - 1)) {
				dice.x--;
				dice.rotateWest();
			}
			break;
		case 3:
			if (dice.isMoveable(dice.y - 1, dice.x)) {
				dice.y--;
				dice.rotateNorth();
			}
			break;
		case 4:
			if (dice.isMoveable(dice.y + 1, dice.x)) {
				dice.y++;
				dice.rotateSouth();
			}
			break;
		}
	}
}