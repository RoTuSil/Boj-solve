#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int index;
	int length;
};

int getFurthest(vector<Node> graph[], int index, bool returnValue) {
	// return a furthest node from node of given index
	// if returnValue is true return Index of furthest node
	// if false return return length from node of given index to furthest node
	int maxNodeIndex = -1;
	int maxNodeLength = -1;
	bool visited[100001] = {};
	queue<Node> q;
	// length value of this queue's Node struct is sum of length from starting node
	q.push({ index, 0 });
	visited[index] = true;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (now.length > maxNodeLength) {
			maxNodeLength = now.length;
			maxNodeIndex = now.index;
		}

		for (int i = 0; i < graph[now.index].size(); i++) {
			if (visited[graph[now.index][i].index]) continue;
			q.push({ graph[now.index][i].index, now.length + graph[now.index][i].length });
			visited[graph[now.index][i].index] = true;
		}
	}
	if (returnValue) return maxNodeIndex;
	return maxNodeLength;
}

vector<Node> graph[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int node;
		cin >> node;
		while (1) {
			int a, b;
			cin >> a;
			if (a == -1) break;
			cin >> b;
			graph[node].push_back({ a,b });
			graph[a].push_back({ node,b });
		}
	}
	int d1 = getFurthest(graph, 1, true);
	int d2 = getFurthest(graph, d1, false);
	cout << d2;
}