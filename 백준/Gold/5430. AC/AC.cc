#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		string command;
		string s;
		int len;
		int arr[100000] = {};
		bool reversed = false;
		cin >> command;
		cin >> len;
		cin >> s;
		for (int i = 0, num = 0, index = 0; i < s.length(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				num *= 10;
				num += s[i] - '0';
				continue;
			}
			if (s[i] == ']' || s[i] == ',') {
				arr[index++] = num;
				num = 0;
			}
		}
		int front = 0, back = len;
		bool error = false;
		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'R') {
				reversed = (reversed ? false : true);
			} else {
				reversed ? back-- : front++;
				if (front > back) {
					error = true;
					cout << "error\n";
					break;
				}
			}
		}
		if (error) continue;
		cout << "[";
		if (reversed) {
			for (int i = back - 1; i >= front; i--) {
				cout << arr[i];
				if (i != front) {
					cout << ",";
				}
			}
		} else {
			for (int i = front; i < back; i++) {
				cout << arr[i];
				if (i != back - 1) {
					cout << ",";
				}
			}
		}
		cout << "]\n";
	}
}