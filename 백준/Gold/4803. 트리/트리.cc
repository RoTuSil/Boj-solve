#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[501];
bool  nodeVisited[501];

bool isTree(int nodeIndex) {

	queue<int> q;
	bool isThisTree = true;
	int parent[501]{};

	q.push(nodeIndex);
	nodeVisited[nodeIndex] = true;
	parent[nodeIndex] = nodeIndex;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			if (now == graph[now][i]) isThisTree = false;
			if (!nodeVisited[graph[now][i]]) {
				q.push(graph[now][i]);
				nodeVisited[graph[now][i]] = true;
				parent[graph[now][i]] = now;
			} else if (parent[now] != graph[now][i]) {
				isThisTree = false;
			}
		}
	}
	return isThisTree;
}

int main() {
	int testCaseNumber = 1;

	while (true) {
		int nodes, edges;
		cin >> nodes >> edges;
		if (nodes == 0 && edges == 0) break;
		int treeCount = 0;
		for (int i = 0; i < edges; i++) {
			int nodeA, nodeB;
			cin >> nodeA >> nodeB;
			graph[nodeA].push_back(nodeB);
			graph[nodeB].push_back(nodeA);
		}
		for (int i = 1; i <= nodes; i++) {
			if (!nodeVisited[i]) {
				if (isTree(i)) treeCount++;
			}
		}
		cout << "Case " << testCaseNumber << ": ";
		if (treeCount <= 0) cout << "No trees.\n";
		else if (treeCount == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << treeCount << " trees.\n";
		for (int i = 0; i <= nodes; i++) {
			graph[i].clear();
			nodeVisited[i] = false;
		}
		testCaseNumber++; // 3 WA because of this fuck
	}
}