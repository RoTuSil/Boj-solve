#include <iostream>
#include <queue>
using namespace std;

struct node { int x; int y;};
vector<node> tree[1001];

int findLengthBetween(int from, int to) {
	bool visited[1001]{};
	queue<node> q;
	q.push({from, 0});
	visited[from] = true;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.x == to) {
			return now.y;
		}
		for (int i = 0; i < tree[now.x].size(); i++) {
			if (!visited[tree[now.x][i].x]) {
				q.push({ tree[now.x][i].x, now.y + tree[now.x][i].y });
				visited[tree[now.x][i].x] = true;
			}
		}
	}
	return -1;
}

int main() {
	int n, findLen;
	cin >> n >> findLen;
	for (int i = 0; i < n - 1; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		tree[a].push_back({ b,len });
		tree[b].push_back({ a,len });
	}
	for (int i = 0; i < findLen; i++) {
		int from, to;
		cin >> from >> to;
		cout << findLengthBetween(from, to) << "\n";
	}

}