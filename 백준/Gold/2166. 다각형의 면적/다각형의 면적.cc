#include <iostream>
#include <iomanip>
using namespace std;

long long arr[10000][2];
int main() {
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	double sumA = 0, sumB = 0;
	for (int i = 0; i < n; i++) {
		sumA += arr[i][0] * arr[(i + 1) % n][1];
		sumB += arr[i][1] * arr[(i + 1) % n][0];
	}
	cout << fixed;
	cout << setprecision(1);
	cout << abs((sumA - sumB)/2.0);
}