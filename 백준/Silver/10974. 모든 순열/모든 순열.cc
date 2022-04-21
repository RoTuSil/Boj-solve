#include <iostream>
using namespace std;

int arr[8], n;
bool used[9]{};
void foo(int d) {
	if (d == n) {
		for(int i = 0;i<n;i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		used[i] = true;
		arr[d] = i;
		foo(d + 1);
		used[i] = false;
	}
}

int main() {
	cin >> n;
	foo(0);
}