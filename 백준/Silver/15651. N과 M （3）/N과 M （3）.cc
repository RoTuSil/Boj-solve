#include <iostream>
using namespace std;

int n, m;
int arr[8];

void visit(int count) {
	if (m == count) {
		for (int i = 0; i < m; i++) printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[count] = i;
		visit(count + 1);
	}
}

int main() {
	cin >> n >> m;
	visit(0);
}