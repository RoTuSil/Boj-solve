#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int n) {
	string num = to_string(n);
	int length = num.length();
	for (int i = 0; i < length; i++) {
		if (num[i] != num[length - 1 - i]) return false;
	}
	return true;
}

bool notPrime[2000001] = { 1,1 };

int main() {
	int n;
	cin >> n;

	for (int i = 2; i < 2000001; i++) {
		if (notPrime[i]) continue;
		for (int j = i * 2; j < 2000001; j += i) {
			notPrime[j] = true;
		}
	}
	while (true) {
		if (!notPrime[n]) {
			if (isPalindrome(n)) {
				cout << n << endl;
				break;
			}
		}
		n++;
	}
}