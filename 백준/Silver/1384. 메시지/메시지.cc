#include <iostream>
#include <vector>
using namespace std;

int main() {
	int group = 0;
	while (1) {
		group++;
		int n;
		cin >> n;
		if (n == 0) break;
		
		string table[20][20];
		
		for (int i = 0; i < n; i++) {
			cin >> table[i][0];

			for (int j = 1; j < n; j++) {
				cin >> table[i][j];
			}
		}
		bool nasty = false;
		cout << "Group " << group << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (table[i][j] == "N") {
					nasty = true;
					cout << table[(i + n - j) % n][0] << " was nasty about " << table[i][0] << "\n";
				}
			}
		}
		
		if (!nasty) cout << "Nobody was nasty\n";

		cout << "\n";
	}
}