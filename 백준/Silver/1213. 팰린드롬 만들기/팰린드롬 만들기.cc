#include <iostream>
using namespace std;
int main() {
	string name;
	int alphabetCount[26]{};
	int oddCharacter = -1;
	bool hasOddCount = false, isPossible = true;
	cin >> name;
	for (char c : name) {
		alphabetCount[c - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabetCount[i] % 2 == 1) {
			if (hasOddCount) {
				cout << "I'm Sorry Hansoo";
				isPossible = false;
				break;
			}
			hasOddCount = true;
			oddCharacter = i;
		}
	}
	if (isPossible) {
		for (int i = 0; i < 26; i++) {
			if (alphabetCount[i] == 1) continue;
			for (int j = 0; j < alphabetCount[i] / 2; j++) {
				cout << (char)(i + 'A');
			}
		}
		if (hasOddCount) {
			cout << (char)(oddCharacter + 'A');
		}
		for (int i = 25; i >= 0; i--) {
			if (alphabetCount[i] == 1) continue;
			for (int j = 0; j < alphabetCount[i] / 2; j++) {
				cout << (char)(i + 'A');
			}
		}
	}
}