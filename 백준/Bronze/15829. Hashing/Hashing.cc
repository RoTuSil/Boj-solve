#include <iostream>
using namespace std;

long long hashChar(int c, int p) {
	long long k = 1;
	for (int i = 0; i < p; i++) {
		k = (k * 31) % 1234567891;
	}
	k = (c * k) % 1234567891;
	return k;
}

int main() {
	int n;
	long long hashValue = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		hashValue += hashChar(s[i] - 'a' + 1, i);
		hashValue %= 1234567891;
	}
	cout << hashValue;
}