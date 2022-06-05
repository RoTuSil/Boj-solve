#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Point {
	// struct for 2D points
	int x;
	int y;

	bool isOut() { return (x == -1 && y == -1); }

	void operator +=(const Point& target) {
		x += target.x;
		y += target.y;
	}
	Point operator +(const Point& target) {
		int nx = x + target.x;
		int ny = y + target.y;
		Point ret = { nx,ny };
		return ret;
	}
	bool operator ==(const Point& target) {
		return ((x == target.x) && (y == target.y));
	}
};

const Point direction[4] = { {0,1},{-1,0},{0,-1},{1,0} };
char d[4] = { 'D','L','U','R' };
int row, col;

struct MarbleSet {
	string path="";
	char board[11][11];
	Point redMarble;
	Point blueMarble;
	Point hole;
	bool operator==(const MarbleSet& target) {
		return (redMarble == target.redMarble && blueMarble == target.blueMarble);
	}
	void dropMarbles(Point dir) {
		while (true) {
			bool ballMoved = false;
			Point temp = redMarble + dir;
			if (!redMarble.isOut()) {
				if (board[temp.y][temp.x] == '.' || board[temp.y][temp.x] == 'O') {
					ballMoved = true;
					board[redMarble.y][redMarble.x] = '.';
					if (board[temp.y][temp.x] == '.')
						board[temp.y][temp.x] = 'R';
					redMarble += dir;
				}
			}
			temp = blueMarble + dir;
			if (!blueMarble.isOut()) {
				if (board[temp.y][temp.x] == '.' || board[temp.y][temp.x] == 'O') {
					ballMoved = true;
					board[blueMarble.y][blueMarble.x] = '.';
					if (board[temp.y][temp.x] == '.')
						board[temp.y][temp.x] = 'B';
					blueMarble += dir;
				}
			}
			//if marble's position is same with hole then set it's position to (-1,-1)
			if (blueMarble == hole) blueMarble = { -1,-1 };
			if (redMarble == hole) redMarble = { -1,-1 };
			if (!ballMoved) break;
		}
	}

	bool isBoardValid() {
		//if blue marble and red marble are both out it's not valid.
		//if blue marble is only out it's not valid too
		return !((blueMarble.isOut() && redMarble.isOut()) || blueMarble.isOut());
	}

	bool isComplete() {
		return (!blueMarble.isOut() && redMarble.isOut());
	}

	string stringify() {
		string s = "";
		for(int i = 0;i<row;i++) {
			for(int j = 0;j<col;j++) {
				if(i==redMarble.y && j==redMarble.x) {
					s+='R';
					continue;
				}
				if(i==blueMarble.y && j==blueMarble.x) {
					s+='B';
					continue;
				}
				if(i==hole.y && j==hole.x) {
					s+='O';
					continue;
				}
				s+=board[i][j];
			}
		}
		return s;
	}
};

MarbleSet game;
queue<MarbleSet> q;
map<string,bool> visited;
int main() {
	int tiltCount = 0;

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> game.board[i];
		for (int j = 0; j < col; j++) {
			if (game.board[i][j] == 'B') game.blueMarble = { j,i };
			if (game.board[i][j] == 'R') game.redMarble = { j,i };
			if (game.board[i][j] == 'O') game.hole = { j,i };
		}
	}
	q.push(game);

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			MarbleSet now = q.front();

			q.pop();
			if (now.isComplete()) {
				cout << tiltCount << '\n';
				return 0;
			}
			MarbleSet cpy;
			for (int k = 0; k < 4; k++) {
				cpy = now;
				cpy.dropMarbles(direction[k]);
				cpy.path += d[k];
				//if board is same after tilting dont push
				if (cpy.isBoardValid() && !(cpy == now)) {
					string result = cpy.stringify();
					if(!visited[result]) {
						visited[result] = true;
						q.push(cpy);
					}
				}
			}
		}
		tiltCount++;
	}
	cout << -1;
}