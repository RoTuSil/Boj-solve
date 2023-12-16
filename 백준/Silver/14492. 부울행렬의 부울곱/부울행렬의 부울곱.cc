#include <iostream>
using namespace std;
int main() {
	bool mat1[300][300]{};
	bool mat2[300][300]{};
	bool matmul[300][300]{};
	int n, count = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat1[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat2[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				matmul[i][j] = mat1[i][k] && mat2[k][j];

				if (matmul[i][j]) {
					count++;
					break;
				}
			}
		}
	}
	cout << count;

}