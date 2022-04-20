#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[100];

bool bfs(int r, int c) {
	queue<int> q;
	bool visited[100] = {};
	q.push(r);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			for (int k = 0; k < graph[now].size(); k++) {
				if (!visited[graph[now][k]]) q.push(graph[now][k]);
				visited[graph[now][k]] = true;
				if (graph[now][k] == c) return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	bool con;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> con;
			if (con) graph[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (bfs(i, j) ? "1 " : "0 ");
		}
		cout << "\n";
	}
}