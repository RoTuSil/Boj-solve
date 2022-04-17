#include <iostream>
#include <stack>
using namespace std;

int arr[500001];
stack<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		while (true) {
			if (s.empty()) {
				cout << "0 ";
				break;
			}
			if (arr[s.top()] > arr[i]) {
				cout << s.top() << " ";
				break;
			}
			if (arr[s.top()] < arr[i])
				s.pop();
		}
		s.push(i);
	}
}