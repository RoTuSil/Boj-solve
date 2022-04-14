#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<int> tree[50];
	bool deleted[50]{};
	int root;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;
			continue;
		}
		tree[parent].push_back(i);
	}
	int del;
	int leafCount = 0;
	cin >> del;
	if (del == root) {
		cout << 0;
		return 0;
	}

	deleted[del] = true;
	queue<int> q;
	q.push(del);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			for (int j = 0; j < tree[now].size(); j++) {
				q.push(tree[now][j]);
				deleted[now] = true;
			}
		}
	}

	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			int childCount =0;
			for (int j = 0; j < tree[now].size(); j++) {
				if (deleted[tree[now][j]]) continue;
				childCount++;
				q.push(tree[now][j]);
			}
			if (childCount == 0) {
				leafCount++;
			}
		}
	}
	cout << leafCount;
}