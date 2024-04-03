#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
	int from;
	int to;
	int weight;

	bool operator<(const Node& target) const {
		return weight > target.weight;
	}
} Node;

priority_queue<Node> pq;
vector<Node> graph[10001];
bool visited[10001];

int main() {

	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ a,b,c });
		graph[b].push_back({ b,a,c });
	}
	int sum = 0;
	pq.push({1,1,0});
	while (!pq.empty()) {
		Node current = pq.top();
		pq.pop();
		if (visited[current.to]) continue;
		sum += current.weight;
		visited[current.to] = true;
		for (Node n : graph[current.to]) {
			if (visited[n.to]) continue;

			pq.push(n);
		}
	}
	cout << sum;
}