#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100002];
int parent[100002] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> q;
	int node;
	cin >> node;
	for (int i = 0; i < node-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	q.push(1);
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int now = q.front();
			q.pop();
			int vSize = tree[now].size();
			for (int k = 0; k < vSize; k++) {
				if (parent[tree[now][k]] != 0) continue;
				parent[tree[now][k]] = now;
				q.push(tree[now][k]);
			}
		}
	}
	for (int i = 2; i <= node; i++) {
		cout << parent[i] << "\n";
	}
}