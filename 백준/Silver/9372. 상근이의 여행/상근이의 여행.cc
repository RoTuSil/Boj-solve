#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int country, plane;
		cin >> country >> plane;
		for (int i = 0; i < plane; i++) {
			int from, to;
			cin >> from >> to;
		}
		cout << country - 1 << "\n";
	}
}