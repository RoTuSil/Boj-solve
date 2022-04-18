#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
vector<int> sum;

int main() {
	int n, everySum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}
	while(!(pq.size() == 1)) {
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		sum.push_back(a + b);
		pq.push(-(a + b));
	}
	for (int i = 0; i < sum.size(); i++) {
		everySum += sum[i];
	}
	cout << everySum;
}