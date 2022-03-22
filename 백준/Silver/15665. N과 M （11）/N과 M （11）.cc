#include <iostream>
using namespace std;

int arr[8] = {};
int arrPrint[8] = {};
int n, m;
bool visited[8] = {};

void NofM(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", arrPrint[i]);
		printf("\n");
		return;
	}
	int lastindex = -1;
	for (int i = 0; i < n; i++) {
		if (lastindex == arr[i]) continue;

		visited[i] = true;
		arrPrint[depth] = arr[i];
		NofM(depth + 1); 
		visited[i] = false;
		lastindex = arr[i];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) 
				arr[j] ^= arr[j + 1] ^= arr[j] ^= arr[j + 1];
		}
	}
	NofM(0);
}