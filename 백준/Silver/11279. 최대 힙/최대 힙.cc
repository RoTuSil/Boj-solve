#include <iostream>
using namespace std;

int arr[100001] = {};
int back = 1;

void insert(int n) {
	arr[back] = n;
	int idx = back;
	while (idx != 1) {
		if (arr[idx / 2] > arr[idx]) break;
		else {
			int temp = arr[idx];
			arr[idx] = arr[idx / 2];
			arr[idx / 2] = temp;
			idx = idx / 2;
		}
	}
	back++;
}

void remove() {
	cout << arr[1] << "\n";
	if (arr[1] == 0) return;

	arr[1] = arr[--back];
	arr[back] = 0;
	int idx = 1;
	while (true) {
		int child = idx * 2;
		if (child + 1 < back && arr[child] < arr[child + 1] && arr[child + 1] != 0) child++;
		if (child >= back || arr[idx] > arr[child] || arr[child] == 0) break;
		int temp = arr[child];
		arr[child] = arr[idx];
		arr[idx] = temp;
		idx = child;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) remove();
		else insert(x);
	}
}