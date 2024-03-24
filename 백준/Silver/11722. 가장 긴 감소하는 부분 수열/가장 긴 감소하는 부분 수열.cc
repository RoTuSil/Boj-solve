#include <iostream>

using namespace std;

int arr[1000];
int dp[1000];
int s;

int d(int n) {
	if (dp[n] != 0) return dp[n] + 1;
	bool hasSmaller = false;
	for (int i = n + 1; i < s; i++) {
		if (arr[i] < arr[n]) {
			dp[n] = max(dp[n], d(i));
			hasSmaller = true;
		}
	}
	if (!hasSmaller) return 1;
	return dp[n] + 1;
}


int main() {
	int m = 0;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < s; i++) {
		m = max(m,d(i));
	}
	cout << m;
}