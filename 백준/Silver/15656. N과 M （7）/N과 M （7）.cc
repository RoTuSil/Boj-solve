#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool visited[9];
int arr[9];
int numArr[9] = {};

void visit(int count, int startNum) {
	if (m == count) {
		for (int i = 0; i < m; i++) printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		//if (visited[i]) continue;
		visited[i] = true;
		arr[count] = numArr[i];
		visit(count + 1, i);
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> numArr[i];
	sort(numArr, numArr + n);
	visit(0,0);
}