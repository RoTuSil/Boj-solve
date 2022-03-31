#include <iostream>
using namespace std;

int main() {
	bool notPrime[300000] = {1,1};
	for (int i = 2; i < 300000; i++) {
		if (notPrime[i]) continue;
		for (int j = i*2; j < 300000; j += i) {
			notPrime[j] = true;
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		int count = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			if (!notPrime[i]) count++;
		}
		cout << count << endl;
	}
}