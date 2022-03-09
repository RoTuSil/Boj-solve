#include <iostream>
using namespace std;

int main() {
	bool notPrime[10001] = { false };
	notPrime[1] = true;
	for (int i = 2; i < 10001; i++) {
		for (int j = i * 2; j < 10001; j += i) {
			if (notPrime[j]) continue;
			notPrime[j] = true;
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int subMin = 10000;
		int a = 0;
		for (int j = 2; j < n/2+1; j++) {
			if (notPrime[j]) continue;
			if (!notPrime[j] && !notPrime[n - j]) {
				if (n - (2 * j) < subMin && (n - (2 * j)) >= 0) {
					a = j;
					subMin = n - (2 * j);
				}
			}
		}
		cout << a << " " << n - a << endl;
	}
}