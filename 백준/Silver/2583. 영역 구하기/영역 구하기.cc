#include <iostream>
#include <algorithm>
using namespace std;

bool visited[100][100];
int m, n, k;

int getArea(int i,int j) {
	if (i < 0 || j < 0 || i >= n || j >= m) return 0;
	if (visited[i][j]) return 0;
	visited[i][j] = true;
	return  (getArea(i + 1, j) + getArea(i - 1, j) +
		getArea(i, j + 1) + getArea(i, j - 1))+1;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int k = y1; k < y2; k++) {
			for (int j = x1; j < x2; j++) {
				visited[k][j] = true;
			}
		}
	}

	int count = 0;
	int arr[100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				arr[count++] = getArea(i, j);
			}
		}
	}
	sort(arr, arr + count);
	cout << count << endl;
	for (int i = 0; i < count; i++) cout << arr[i] << " ";

}