#include <iostream>
using namespace std;

int numbers[13]={};
int printarr[6]={};
bool used[13]={};
int length;

void printArray(int depth, int lastindex) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << printarr[i] << " ";
		} cout << "\n";
		return;
	}
	for (int i = lastindex; i < length; i++) {
		if (used[i]) continue;
		used[i] = true;
		printarr[depth] = numbers[i];
		printArray(depth + 1, i);
		used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	while (true) {
		cin >> length;
		if (length == 0) break;
		for (int i = 0; i < length; i++)
			cin >> numbers[i];
		printArray(0, 0);
		cout << "\n";
	}
}