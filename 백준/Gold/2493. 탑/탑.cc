#include <iostream>
#include <stack>
#include <string>
using namespace std;

int arr[500001];
stack<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string ans="";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		while (true) {
			if (s.empty()) {
				ans += "0 ";
				break;
			}
			if (arr[s.top()] > arr[i]) {
				ans += to_string(s.top()) + " ";
				break;
			}else s.pop();
		}
		s.push(i);
	}
	cout << ans;
}