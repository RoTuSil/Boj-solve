#include <iostream>
#include <string>
using namespace std;

string s, target;

bool findFrom(int index) {
	for (int i = 0; i < target.length(); i++) {
		if (s[index + i] != target[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	getline(cin, s);
	getline(cin, target);
	int idx = 0, f = 0;
	for (int i = 0; i < s.length(); i++) {
		if (findFrom(i)) {
			f++;
			i += target.length()-1;
		}
	}
	cout << f;
}