#include <iostream>
#include <vector>

using namespace std;

vector<int> v[2000];
bool visited[2000];

bool find(int n, int depth) {
	if (depth == 5) { cout << "1" << endl; return true; }

	for (int i : v[n]) {
		if (visited[i]) continue;

		visited[i] = true;
		if (find(i, depth + 1)) return true;;
		visited[i] = false;
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		if (find(i, 0)) return 0;
	}

	cout << "0" << endl;

}