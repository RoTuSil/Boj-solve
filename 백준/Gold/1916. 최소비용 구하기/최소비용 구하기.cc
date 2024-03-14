#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
	int to;
	int dist;
	int before = 0;

	bool operator<(const node& other) const {
		return dist > other.dist;
	}

} node;

vector<node> v[2000];
int distances[2000];
int n;

void dijkstra(int start) {
	distances[start] = 0;
	priority_queue<node> q;
	q.push({start,0});
	while (!q.empty()) {
		node current = q.top();
		q.pop();
		if (distances[current.to] < current.dist) continue;
		for (node next : v[current.to]) {

			int d = distances[current.to] + next.dist;
			if (d < distances[next.to]) {
				distances[next.to] = d;
				q.push({ next.to ,d});
			}
		}
	}
}
int main() {
	int e;
	int point1, point2;
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		distances[i] = 200000000;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });

	}
	cin >> point1 >> point2;
	dijkstra(point1);
	cout << distances[point2];
}