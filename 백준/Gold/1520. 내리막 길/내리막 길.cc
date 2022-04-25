#include <iostream>
#include <iomanip>
using namespace std;

struct Point {
	int x;
	int y;
};

Point moveset[4] = { {0,1},{1,0},{-1,0},{0,-1} };

bool visited[500][500] = {};
int map[500][500] = {};
int dp[500][500] = {};
int row, col;

void dfs(Point pos) {
	if (pos.x == col - 1 && pos.y == row - 1) {
		dp[pos.y][pos.x] = 1;
		return;
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int nx = pos.x + moveset[i].x;
		int ny = pos.y + moveset[i].y;
		if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
			if (map[ny][nx] < map[pos.y][pos.x]) {
				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					dfs({ nx,ny });
				}
				sum += dp[ny][nx];
			}
		}
	}
	dp[pos.y][pos.x] = sum;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	visited[0][0] = true;
	dfs({ 0,0 });
	cout << dp[0][0];
}