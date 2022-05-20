#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		map<int, int> valueCount;
		int inputCount, input;
		char command;
		cin >> inputCount;
		for (int i = 0; i < inputCount; i++) {
			cin >> command >> input;

			if (command == 'I') {
				maxHeap.push(input);
				minHeap.push(input);
				valueCount[input]++;
				continue;
			} 
			if (command == 'D') {
				if (input == -1) {
					while (!minHeap.empty()) {
						int m = minHeap.top();
						if (valueCount[m] > 0) {
							valueCount[m]--;
							minHeap.pop();
							break;
						}
						minHeap.pop();
					}
					continue;
				}
				if (input == 1) {
					while (!maxHeap.empty()) {
						int m = maxHeap.top();
						if (valueCount[m] > 0) {
							valueCount[m]--;
							maxHeap.pop();
							break;
						}
						maxHeap.pop();
					}
					continue;
				}
			}
		}
		
		while (!maxHeap.empty()) {
			if (valueCount[maxHeap.top()] == 0) {
				maxHeap.pop();
			} else break;
		}
		while (!minHeap.empty()) {
			if (valueCount[minHeap.top()] == 0) {
				minHeap.pop();
			} else break;
		}
		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY\n";
			continue;
		}
		cout << maxHeap.top() << " " << minHeap.top() << "\n";
	}
}