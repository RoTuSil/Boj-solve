#include <iostream>
#include <queue>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		queue<int> q;
		vector<int> graph[20001];
		bool visited[20001] = {};
		bool wrong = false;
		bool color = 1;
		int colorRB[20001] = {};
		int vertices, edges;
		cin >> vertices >> edges;

		for (int i = 0; i < edges; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= vertices; i++) {
			if (!visited[i]) {
				q.push(i);
				colorRB[i] = (color ? 1 : 2);
				color = !color;
				visited[i] = true;
				break;
			}
		}
		while (!q.empty()) {
			if (wrong) break;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				if (wrong) break;
				int now = q.front();
				q.pop();
				for (int j = 0; j < graph[now].size(); j++) {
					if (!visited[graph[now][j]]) {
						q.push(graph[now][j]);
						visited[graph[now][j]] = true;
						colorRB[graph[now][j]] = (color ? 1 : 2);

					} else {
						if (colorRB[graph[now][j]] == colorRB[now]) {
							wrong = true;
							break;
						}
					}
				}
			}
			if (q.empty()) {
				for (int i = 1; i <= vertices; i++) {
					if (!visited[i]) {
						q.push(i);
						colorRB[i] = (color ? 1 : 2);
						visited[i] = true;
						break;
					}
				}
			}
			color = !color;
		}
		cout << (wrong ? "NO\n" : "YES\n");
	}
}