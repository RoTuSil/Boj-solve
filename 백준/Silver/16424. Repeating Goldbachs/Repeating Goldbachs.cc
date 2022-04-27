#include <iostream>
using namespace std;

bool notPrime[1000000] = { 1,1 };
int main() {
	for (int i = 2; i < 1000000; i++) {
		for (int j = i * 2; j < 1000000; j += i) {
			notPrime[j] = true;
		}
	}

	int goldbachCount = 0;
	int x;
	cin >> x;
	while (x >= 3) {
		int i = 2;
		while (1) {
			if (!notPrime[i] && !notPrime[x - i]) break;
			i++;
		}
		x -= i * 2;
		goldbachCount++;
	}
	cout << goldbachCount;
}