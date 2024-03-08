#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
	int to;
	int dist;
};

vector<node> v[801];

void dijkstra(int start, int *distance) {
	distance[start] = 0;
	bool visited[801]{};
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		int s = v[current].size();
		for (int i = 0; i < s; i++) {
			node currentNode = v[current][i];
			int d = distance[current] + currentNode.dist;
			if (distance[currentNode.to] > d)
				distance[currentNode.to] = d;

			visited[current] = true;
			if (visited[v[current][i].to]) continue;
			q.push(v[current][i].to);
		}
	}
}

int main() {
	int distanceStart[801]{};
	int distanceEnd[801]{};
	int distanceMid[801]{};
	int n, e;
	cin >> n >> e;
	int point1, point2;
	for (int i = 1; i <= n; i++) {
		distanceStart[i] = 100000000;
		distanceEnd[i] =   100000000;
		distanceMid[i] =   100000000;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> point1 >> point2;

	dijkstra(1, distanceStart);
	dijkstra(n, distanceEnd);
	dijkstra(point1, distanceMid);

	int distanceA = distanceStart[point1] + distanceEnd[point2] + distanceMid[point2];
	int distanceB = distanceStart[point2] + distanceEnd[point1] + distanceMid[point2];
	if (distanceA >= 100000000 || distanceB >= 10000000) {
		cout << -1;
		return 0;
	}
	cout << min(distanceA, distanceB);
}