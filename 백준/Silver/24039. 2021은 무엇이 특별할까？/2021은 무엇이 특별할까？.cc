#include <iostream>
using namespace std;

int main() {	
	bool notPrime[10001];
	int primeArray[10000];
	int n;
	notPrime[1] = true;
	for (int i = 2; i < 10001; i++) {
		for (int j = i * 2; j < 10001; j += i) {
			if (notPrime[j]) continue;
			notPrime[j] = true;
		}
	}
	for(int i = 0,idx=0;i<10000;i++) {
		if(notPrime[i]) continue;
		primeArray[idx++] = i;
	}
	cin >> n;
	for(int i =0;i<10000;i++) {
		if(primeArray[i] * primeArray[i+1]>n) {
			cout << primeArray[i] * primeArray[i+1];
			break;
		}
	}
}