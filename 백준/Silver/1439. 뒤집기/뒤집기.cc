#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	char before = s[0];
	int c = 0;
	for (int i = 1; i < s.length();i++) {
		if (before != s[i]) c++;
		before = s[i];
	}
	cout << (c % 2 ? (c + 1) / 2 : c / 2);
}