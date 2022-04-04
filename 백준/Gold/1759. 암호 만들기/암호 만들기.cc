#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
int aeiou = 0, otherchar = 0;
char ch[15]{};
bool used[15]{};
string password;

void createPassword(int depth, int lastindex) {
	if (depth == l) {
		if (aeiou >= 1 && otherchar >= 2)
			cout << password << "\n";
		return;
	}
	for (int i = lastindex; i < c; i++) {

		if (used[i]) continue;
		used[i] = true;
		password.push_back(ch[i]);
		if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') {
			aeiou++;
			createPassword(depth + 1, i);
			aeiou--;
		} else {
			otherchar++;
			createPassword(depth + 1, i);
			otherchar--;
		}
		used[i] = false;
		password.pop_back();
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> ch[i];
	}
	sort(ch, ch + c);
	createPassword(0, 0);
}