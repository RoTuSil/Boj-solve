#include <iostream>
using namespace std;

int parent[1000001];

int findParent(int target) {
	if (parent[target] == target) return target;
	parent[target] = findParent(parent[target]);
	return parent[target];
}

void mergeParent(int a, int b) {
	int setA = findParent(a);
	int setB = findParent(b);

	if (setA > setB) parent[setA] = setB;
	else parent[setB] = setA;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int state, a, b;
		cin >> state >> a >> b;
		if (state) {
			cout<< (findParent(a) == findParent(b) ? "YES\n" : "NO\n");
		} else {
			mergeParent(a, b);
		}
	}
}