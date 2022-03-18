#include <iostream>
using namespace std;

int n, m;
bool visited[9];
int arr[9];

void visit(int count, int num) {
	if (m == count) {
		for (int i = 0; i < m; i++) printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	for (int i = num; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		arr[count] = i;
		visit(count + 1, i);
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	visit(0, 1);
}