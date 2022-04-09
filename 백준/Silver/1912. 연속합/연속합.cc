#include <iostream>
using namespace std;
int main() {
	int n;
	int arr[100000]{};
	int dp[100000]{};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (dp[i] > sum) sum = dp[i];
	}
	cout << sum;
}