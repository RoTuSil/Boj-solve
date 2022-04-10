#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{
	int i;
	int j;
};

bool c(const Pos& a, const Pos& b) {
	if (a.i < b.i) return true;
	if (a.i == b.i) return a.j < b.j;
	return false;
}

int map[20][20];
int sharkSize = 2;
int fishAte = 0;
int n, px, py;
const int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };

int eatClosest() {
	//	move shark to the closest and smaller fishusing bfs
	//	then return how many times passed
	queue<Pos> q;
	vector<Pos> fish;
	bool visited[20][20]{};
	int timePassed = 0;
	bool fishFound = false;
	visited[py][px] = true;
	q.push({ py,px });
	while (!q.empty()) {
		if (fishFound) break;
		int s = q.size();
		for (int i = 0; i < s; i++) {
			Pos now = q.front();
			q.pop();
			if (map[now.i][now.j] < sharkSize && map[now.i][now.j] != 0) {
				fish.push_back({ now.i,now.j });
				fishFound = true;
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int npy = now.i + dir[k][0];
				int npx = now.j + dir[k][1];
				if (npx >= 0 && npy >= 0 && npx < n && npy < n) {
					if (visited[npy][npx]) continue;
					if (map[npy][npx] > sharkSize) continue;
					q.push({ npy,npx });
					visited[npy][npx] = true;
				}
			}
		}
		timePassed++;
	}
	if (fishFound) {
		sort(fish.begin(), fish.end(),c);
		map[py][px] = 0;
		map[fish[0].i][fish[0].j] = 0;
		py = fish[0].i;
		px = fish[0].j;
		fishAte++;
		if (fishAte == sharkSize) {
			fishAte = 0;
			sharkSize++;
		}
		return --timePassed;
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) { 
				px = j;
				py = i;
			}
		}
	}
	int totalTimePassed = 0;
	while (true) {
		int t = eatClosest();
		if (t == -1) break;
		totalTimePassed += t;
	}
	cout << totalTimePassed;
}
