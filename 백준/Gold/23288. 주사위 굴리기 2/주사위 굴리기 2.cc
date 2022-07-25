#include <iostream>
#include <queue>
using namespace std;

int board[21][21];
int width, height, moveCount;

struct Point {
	int x;
	int y;
};

const Point moveset[4] = { {1,0},{0,1},{-1,0},{0,-1} };
						// 동	 남	   서	  북
char temp[4] = { 'e','s','w','n' };

struct Dice {
	int side[6] = {2,4,1,3,5,6};
	int direction = 0;
	Point position{1,1};

	int getBottom() {
		return side[5];
	}
	void rollLeft() {
		int newside[6] = { side[0],side[2],side[3],side[5],side[4],side[1] };
		for (int i = 0; i < 6; i++) 
			side[i] = newside[i];
	}
	void rollRight() {
		int newside[6] = { side[0],side[5],side[1],side[2],side[4],side[3] };
		for (int i = 0; i < 6; i++) 
			side[i] = newside[i];
	}
	void rollUp() {
		int newside[6] = { side[2],side[1],side[4],side[3],side[5],side[0] };
		for (int i = 0; i < 6; i++) 
			side[i] = newside[i];
	}
	void rollDown() {
		int newside[6] = { side[5],side[1],side[0],side[3],side[2],side[4] };
		for (int i = 0; i < 6; i++) 
			side[i] = newside[i];
	}

	void roll() {
		int nx = position.x + moveset[direction].x;
		int ny = position.y + moveset[direction].y;
		if (nx <= 0 || ny <= 0 || nx > width || ny > height) {
			direction = (direction + 2) % 4;
		}
		nx = position.x + moveset[direction].x;
		ny = position.y + moveset[direction].y;
		switch (direction) {
			case 0:
				rollRight();
				break;
			case 1:
				rollDown();
				break;
			case 2:
				rollLeft();
				break;
			case 3:
				rollUp();
				break;
		}
		Point np = { nx,ny };
		if (getBottom() > board[ny][nx]) {
			direction = (direction + 1) % 4;
		} else if (getBottom() < board[ny][nx]) {
			direction = (direction + 3) % 4;
		}
		position = np;
	}

	int getScore() {
		int currentScore = 1;
		int target = board[position.y][position.x];
		bool visited[21][21]{};
		visited[position.y][position.x] = true;
		queue<Point> q;
		q.push(position);
		while (!q.empty()) {
			Point now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = now.x + moveset[i].x;
				int ny = now.y + moveset[i].y;
				if (nx > 0 && ny > 0 && nx <= width && ny <= height) {
					if (board[ny][nx] == target && !visited[ny][nx]) {
						currentScore++;
						visited[ny][nx] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		return currentScore * target;
	}
};

int main() {
	int score = 0;
	Dice dice;

	cin >> height >> width;
	cin >> moveCount;

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < moveCount; i++) {
		dice.roll();
		score += dice.getScore();
	}
	cout << score;
}