#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	cin.ignore();
	for (int t = 0; t < tc; t++) {
		string s;
		stack<char> st;
		getline(cin, s);
		for (int i = 0; i < s.length();i++) {
			if(s[i] != ' ') st.push(s[i]);

			if (s[i] == ' ' || i == s.length()-1) {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << " ";
			}
		}
		cout << "\n";
	}
}