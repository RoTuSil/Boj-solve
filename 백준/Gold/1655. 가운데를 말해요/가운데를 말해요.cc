#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if (maxheap.size() > minheap.size()) {
			minheap.push(n);
		} else {
			maxheap.push(n);
		}
		if (i) {
			while (maxheap.top() > minheap.top()) {
				int a, b;
				a = maxheap.top();
				b = minheap.top();
				maxheap.pop();
				minheap.pop();
				minheap.push(a);
				maxheap.push(b);
			}
			if (maxheap.size() == minheap.size()) {
				cout << min(maxheap.top(), minheap.top());
			} else {
				cout << (maxheap.size() > minheap.size() ? maxheap.top() : minheap.top());
			}
			cout << "\n";
		} else {
			cout << maxheap.top() << "\n";
			continue;
		}
	}
}