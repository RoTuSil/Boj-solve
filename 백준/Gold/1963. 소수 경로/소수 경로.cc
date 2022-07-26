#include <iostream>
#include <queue>
using namespace std;

bool notPrime[10000] = { 1,1 };

int findPrimeSteps(int a, int b) {
	bool found = false;
	int stepcount = 0;
	bool visited[10000]{};
	visited[a] = true;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (now == b) {
				found = true;
				break;
			}
			for (int j = 0; j < 10; j++) {
				if (j) {
					int n = j * 1000 + now % 1000;
					if (!visited[n] && !notPrime[n]) {
						q.push(n);
						visited[n] = true;
					}
				}
				int n = j * 100 + (now / 1000) * 1000 + now % 100;
				if (!visited[n] && !notPrime[n]) {
					q.push(n);
					visited[n] = true;
				}
				n = j * 10 + (now / 100) * 100 + now % 10;
				if (!visited[n] && !notPrime[n]) {
					q.push(n);
					visited[n] = true;
				}
				n = j + (now / 10) * 10;
				if (!visited[n] && !notPrime[n]) {
					q.push(n);
					visited[n] = true;
				}
			}
		}
		if (found) break;
		stepcount++;
	}
	return stepcount;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 2; i < 10000; i++) {
		for (int j = i * 2; j < 10000; j += i) {
			notPrime[j] = true;
		}
	}
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int a, b;
		cin >> a >> b;
		cout << findPrimeSteps(a, b) << "\n";
	}
}