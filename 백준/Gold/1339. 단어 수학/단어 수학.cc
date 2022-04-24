#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	string word[10];
	int arr[26];
	for (int i = 0; i < 26; i++) arr[i] = -1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
		int l = word[i].length();
		for (int j = l - 1; j >= 0; j--) {
			if (arr[word[i][j] - 'A'] == -1)arr[word[i][j] - 'A'] = 0;
			arr[word[i][j] - 'A'] += pow(10, l-j-1);
		}
	}
	sort(arr, arr + 26, greater<int>());
	int sum = 0;
	for (int i = 0, v = 9; i < 26; i++) {
		if (arr[i] == -1) break;
		sum += arr[i] * v--;
	}
	cout << sum;
}