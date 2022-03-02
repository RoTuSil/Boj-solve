#include <iostream>
using namespace std;

int main() {
	int arr[1001][3]={0},n;
	cin >> n;
	for(int i = 1;i<=n;i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for(int i = 2;i<=n;i++) {
		arr[i][0] += min(arr[i-1][1],arr[i-1][2]);
		arr[i][1] += min(arr[i-1][0],arr[i-1][2]);
		arr[i][2] += min(arr[i-1][1],arr[i-1][0]);
	}
	cout << min(arr[n][0],min(arr[n][1],arr[n][2]));
}