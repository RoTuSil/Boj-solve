#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) cout << "*";
	else {
		for (int i = 1; i <= 2*n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((i + j) % 2 == 0) cout << "*";
				else cout << " ";
			}cout << endl;
		}
	}
}