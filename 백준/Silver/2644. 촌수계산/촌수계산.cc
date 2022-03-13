#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n,m,from,to,chon=0;
	queue<int> q;
	bool graph[101][101] = {};
	bool visited[101] = {};
	cin >> n;
	cin >> from >> to;
	q.push(from);
	visited[from] = true;
	cin >> m;
	for (int t = 0; t < m; t++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (now == to) {
				cout << chon;
				return 0;
			}
			for (int k = 1; k <= n; k++) {
				if (graph[now][k] && !visited[k]) {
					q.push(k);
					visited[k] = true;
				}
			}
		}
		chon++;
	}
	cout << "-1";
}