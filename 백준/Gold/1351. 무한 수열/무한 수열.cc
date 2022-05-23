#include <iostream>
#include <map>
using namespace std;

map<long long, long long> dp;
int p, q;

long long infiniteArray(long long n) {
	if (n == 0) return 1;
	if (dp[n]) return dp[n];
	else dp[n] = infiniteArray(n / p) + infiniteArray(n / q);
	return dp[n];
}

int main() {
	long long n;
	cin >> n >> p >> q;
	cout << infiniteArray(n);
}