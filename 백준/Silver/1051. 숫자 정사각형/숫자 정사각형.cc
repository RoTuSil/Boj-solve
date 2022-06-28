#include <iostream>
using namespace std;

int main() {
	int height, width;
	int maxsize = 0;
	string s[50];
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		cin >> s[i];
	}
	for (int size = 0; size < max(height, width); size++) {
		for (int h = 0; h < height - size; h++) {
			for (int w = 0; w < width - size; w++) {
				if (s[h][w] == s[h + size][w + size] && s[h][w + size] == s[h + size][w + size]
					&& s[h + size][w + size] == s[h + size][w]) {
					maxsize = max(maxsize, (size+1)*(size+1));
				}
			}
		}
	}
	cout << maxsize;
}