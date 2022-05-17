#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[300001];
queue<int> q;
bool visited[300001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int city, road, pathLength, startCity;
	vector<int> foundCity;
	bool cityFound = false;
	cin >> city >> road >> pathLength >> startCity;
	for (int i = 0; i < road; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	q.push(startCity);
	visited[startCity] = true;
	int searchDepth = 1;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			for (int k = 0; k < graph[now].size(); k++) {
				if (!visited[graph[now][k]]) {
					q.push(graph[now][k]);
					visited[graph[now][k]] = true;
					if (searchDepth == pathLength) {
						cityFound = true;
						foundCity.push_back(graph[now][k]);
					}
				}
			}
		}
		searchDepth++;
	}
	if (cityFound) {
		sort(foundCity.begin(), foundCity.end());
		for (int i = 0; i < foundCity.size(); i++) {
			cout << foundCity[i] << "\n";
		}
		return 0;
	}
	cout << -1;
}