#include <iostream>
#include <deque>
using namespace std;

struct hns {
	int pos;
	int time = 0;
};

int main() {
	int n, k;
	deque<hns> q;
	bool map[100001]{};
	cin >> n >> k;
	map[n] = true;
	q.push_back({ n,0 });
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			hns now = q.front();
			q.pop_front();
			if (now.pos == k) {
				cout << now.time;
				return 0;
			}
			if (now.pos * 2 <= 100000) {
				if (!map[now.pos * 2]) {
					q.push_front({ now.pos * 2,now.time });
					map[now.pos * 2] = true;
				}
			}
			if (now.pos + 1 <= 100000) {
				if (!map[now.pos + 1]) {
					q.push_back({ now.pos + 1 ,now.time + 1 });
					map[now.pos + 1] = true;
				}
			}
			if (now.pos - 1 >= 0) {
				if (!map[now.pos - 1]) {
					q.push_back({ now.pos - 1, now.time + 1 });
					map[now.pos - 1] = true;
				}
			}
		}
	}
}