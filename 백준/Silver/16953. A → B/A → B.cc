#include <iostream>
#include <queue>
using namespace std;

int main() {
	int a, b, o = 0;
	cin >> a >> b;
	queue<int> q;
	q.push(b);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (now == a) {
				cout << o + 1;
				return 0;
			}
			if (now % 2 == 0 && now / 2 > 0) {
				q.push(now / 2);
			}
			if (now % 10 == 1 && (now - 1) / 10 > 0) {
				q.push((now - 1) / 10);
			}
		}
		o++;
	}
	cout << -1;
}