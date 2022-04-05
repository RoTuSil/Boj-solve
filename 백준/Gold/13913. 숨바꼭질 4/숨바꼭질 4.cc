#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int n, k, time = 0;
	queue<int> q;
	bool map[100001]{};
	int before[100001]{};
	for (int i = 0; i < 100001; i++) before[i] = -1;
	cin >> n >> k;
	map[n] = true;
	q.push(n);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (now == k) {
				cout << time << endl;
				stack<int> s;
				int track = k;
				while (track != -1) {
					s.push(track);
					track = before[track];
				}
				while (!s.empty()) {
					cout << s.top() << " ";
					s.pop();
				}
				return 0;
			}
			if (now + 1 <= 100000) {
				if (!map[now + 1]) {
					before[now + 1] = now;
					q.push(now + 1);
					map[now + 1] = true;
				}
			}
			if (now - 1 >= 0) {
				if (!map[now - 1]) {
					before[now - 1] = now;
					q.push(now - 1);
					map[now - 1] = true;
				}
			}
			if (now * 2 <= 100000) {
				if (!map[now * 2]) {
					before[now * 2] = now;
					q.push(now * 2);
					map[now * 2] = true;
				}
			}
		}
		time++;
	}
}