#include <iostream>
#include <queue>
using namespace std;

struct Position{
	int y;
	int x;

	void operator+=(const Position& input) {
		y += input.y;
		x += input.x;
	}
};

const Position directions[4] = { {-1,0},{0,1},{1,0},{0,-1} };

//1==snake or walls	10==apple	0==empty
int map[101][101] = {};

struct Snake {
	queue<Position> body;
	int dir = 1;
	bool isDead = false;
	void init() {
		body.push({ 0,0 });
		map[0][0] = 1;
	}
	void moveForward() {
		Position newPos = body.back();
		newPos += directions[dir];
		//collided with body or walls
		if (newPos.x<0||newPos.y<0) {
			isDead = true;
			return;
		}
		if (map[newPos.y][newPos.x] == 1) {
			isDead = true;
			return;
		}
		// if there is no apple pop the tail so the snake's length is same
		if (map[newPos.y][newPos.x] != 10) {
			Position temp = body.front();
			map[temp.y][temp.x] = 0;
			body.pop();
		}
		//move forward
		map[newPos.y][newPos.x] = 1;
		body.push(newPos);

	}

	void turnLeft() {
		dir--;
		if (dir == -1) dir = 3;
	}
	void turnRight() {
		dir++;
		if (dir == 4) dir = 0;
	}

};

int main() {

	Snake snake;
	int boardSize, appleCount;
	int timePassed = 0;
	int turnCount;

	snake.init();
	cin >> boardSize;

	for (int i = 0; i <= boardSize; i++) {
		map[i][boardSize] = 1;
		map[boardSize][i] = 1;
	}

	cin >> appleCount;
	for (int i = 0; i < appleCount; i++) {
		int tmpr, tmpc;
		cin >> tmpr >> tmpc;
		map[tmpr-1][tmpc-1] = 10;
	}
	cin >> turnCount;
	int moveList[100][2];
	for (int i = 0; i < turnCount; i++) {
		int duration;
		char turnDir;
		cin >> duration >> turnDir;
		moveList[i][0] = duration;
		moveList[i][1] = turnDir;
	}
	int moveindex = 0;
    
	while (!snake.isDead) {
		if (timePassed == moveList[moveindex][0]) {
			if (moveList[moveindex][1] == 'D') snake.turnRight();
			else snake.turnLeft();
			moveindex++;
		}
		snake.moveForward();
		timePassed++;
	}

	cout << timePassed;
}