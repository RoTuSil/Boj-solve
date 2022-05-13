#include <iostream>
using namespace std;

int arr[2000];
int palindrome[2000][2000];

bool isPalindrome(int start, int end) {
	if (palindrome[start][end] == -1) return false;
	else if (palindrome[start][end] == 1) return true;
	if (start == end) return true;
	if (end - start == 2 || end - start == 1) {
		return arr[start] == arr[end];
	}
	palindrome[start + 1][end - 1] = (isPalindrome(start + 1, end - 1) ? 1 : -1);
	if (palindrome[start + 1][end - 1] == 1) {
		palindrome[start][end] = (arr[start] == arr[end] ? 1 : -1);
		return arr[start] == arr[end];
	}
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ask;
	cin >> ask;
	for (int i = 0; i < ask; i++) {
		int s, e;
		cin >> s >> e;
		cout << isPalindrome(s - 1, e - 1) << "\n";
	}
}