#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	while (true) {
		string s;
		bool isValid = true;
		getline(cin, s);
		if (s == ".") return 0;
		stack<char> equal;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') equal.push('(');
			else if (s[i] == '[') equal.push('[');
			else if (s[i] == ')') {
				if (equal.empty()) {
					isValid = false;
					break;
				}
				if (equal.top() == '(') {
					equal.pop();
				} else {
					isValid = false;
					break;
				}
			} else if (s[i] == ']') {
				if (equal.empty()) {
					isValid = false;
					break;
				}
				if (equal.top() == '[') {
					equal.pop();
				} else {
					isValid = false;
					break;
				}
			}
		}
		if (!equal.empty()) isValid = false;
		cout << (isValid ? "yes" : "no") << endl;
	}
}