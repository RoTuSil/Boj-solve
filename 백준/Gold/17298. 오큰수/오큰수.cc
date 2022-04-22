#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> nge;
stack<int> answer;
int arr[1000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		while (1) {
			if (nge.empty()) {
				answer.push(-1);
				break;
			}
			if (nge.top() > arr[i]) {
				answer.push(nge.top());
				break;
			}
			if (nge.top() <= arr[i]) nge.pop();
		}
		nge.push(arr[i]);
	}
	string finalAnswer="";
	while (!answer.empty()) {
		finalAnswer += to_string(answer.top()) + " ";
		answer.pop();
	}
	cout << finalAnswer;
}