#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int h = 1; h <= 9; h++) {
		for (int e = 0; e <= 9; e++) {
			if (e == h) continue;
			for (int l = 0; l <= 9; l++) {
				if (l == e || l == h) continue;
				for (int o = 0; o <= 9; o++) {
					if (o == l || o == e || o == h) continue;
					for (int w = 1; w <= 9; w++) {
						if (w == l || w == e || w == h || w==o) continue;
						for (int r = 0; r <= 9; r++) {
							if (r == l || r == e || r == h || r == o || r == w) continue;
							for (int d = 0; d <= 9; d++) {
								if (d == l || d == e || d == h || d == o || d == w || d == r) continue;
								int hello = h * 10000 + e * 1000 + l * 100 + l * 10 + o;
								int world = w * 10000 + o * 1000 + r * 100 + l * 10 + d;								
								if (hello + world == n) {
									cout << "  " << hello << endl;
									cout << "+ " << world << endl;
									cout << "-------" << endl;
									if (n >= 100000) cout << " ";
									else cout << "  ";
									cout << n;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "No Answer";
}