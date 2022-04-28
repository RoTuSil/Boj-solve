#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int index;
	int length;
};

vector<Node> graph[10001];

int getFurthest(int index, bool returnValue) {
	// return a furthest node from node of given index
	// if returnValue is true return Index of furthest node
	// if false return return length from node of given index to furthest node
	int maxNodeIndex = -1;
	int maxNodeLength = -1;
	bool visited[10001] = {};
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

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		graph[a].push_back({ b,v });
		graph[b].push_back({ a,v });
	}
	int d1 = getFurthest(1,true);
	int d2 = getFurthest(d1,false);
	cout << d2;
}