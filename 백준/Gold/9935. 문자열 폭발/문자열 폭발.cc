#include <iostream>
#include <vector>
using namespace std;
int main() {
	string s, bomb;
	cin >> s;
	cin >> bomb;
	vector<char> v;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]);
		if (v.size() >= bomb.length()) {
			bool noBomb = false;
			for (int k = 0; k < bomb.length(); k++) {
				int checkIdx = v.size() - bomb.length() + k;
				if (v[checkIdx] != bomb[k]) {
					noBomb = true;
					break;
				}
			}
			if (noBomb) continue;
			for (int k = 0; k < bomb.length(); k++) {
				v.pop_back();
			}
		}
	}
	if (v.empty()) {
		cout << "FRULA";
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}