#include <iostream>
#include <list>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		list<char> li;
		list<char>::iterator pos;
		pos = li.end();
		cin >> s;
		for (int i = 0; i < s.length(); i++) {

			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
				li.insert(pos, s[i]);
				continue;
			}
			if (s[i] == '>') {
				if (pos == li.end()) continue;
				pos++;
			}
			if (s[i] == '<') {
				if (pos == li.begin()) continue;
				pos--;
			}
			if (s[i] == '-') {
				if(!li.empty() && pos!=li.begin())
					pos = li.erase(--pos);
			}
		}
		for (list<char>::iterator sp = li.begin(); sp != li.end(); ++sp) {
			cout << *sp;
		}
		cout << '\n';
	}
}