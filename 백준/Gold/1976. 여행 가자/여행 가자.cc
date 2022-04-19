#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> connections[201];
	int plan[1000] = {};
	queue<int> q;
	int n;
	int city;
	cin >> n;
	cin >> city;
	for (int i = 1; i <= n; i++) {
		for (int j = 1, c; j <= n; j++) {
			cin >> c;
			if (c == 1) connections[i].push_back(j);
		}
	}
	for (int i = 0; i < city; i++) {
		cin >> plan[i];
	}
	
	for (int p = 0; p < city - 1; p++) {
		bool visited[201] = {};
		q.push(plan[p]);
		visited[plan[p]] = true;
		bool found = false;
		while (!q.empty()) {
			if (found) break;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int now = q.front();
				if (now == plan[p + 1]) {
					found = true;
					break;
				}
				q.pop();
				for (int k = 0; k < connections[now].size(); k++) {
					if (!visited[connections[now][k]]) {
						q.push(connections[now][k]);
						visited[connections[now][k]] = true;
					}
				}
			}
		}
		if (!found) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}