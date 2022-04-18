#include <iostream>
#include <queue>
using namespace std;

struct absInt {
	int x;
	bool operator> (const absInt& target) const {
		if (abs(target.x) == abs(x)) {
			return x < target.x;
		} else return abs(x) < abs(target.x);
	}
	bool operator< (const absInt& target) const {
		if (abs(target.x) == abs(x)) {
			return x > target.x;
		} else return abs(x) > abs(target.x);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	priority_queue<absInt> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!x) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top().x << "\n";
				pq.pop();
			}
		} else {
			pq.push({x});
		}
	}
}