#include <iostream>
using namespace std;

int maxdp[2][3];
int mindp[2][3];
int game[100001][3];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> game[i][j];
		}
		maxdp[1][0] = max(maxdp[0][0], maxdp[0][1]) + game[i][0];
		maxdp[1][1] = max(maxdp[0][0], max(maxdp[0][1], maxdp[0][2])) + game[i][1];
		maxdp[1][2] = max(maxdp[0][1], maxdp[0][2]) + game[i][2];

		mindp[1][0] = min(mindp[0][0], mindp[0][1]) + game[i][0];
		mindp[1][1] = min(mindp[0][0], min(mindp[0][1], mindp[0][2])) + game[i][1];
		mindp[1][2] = min(mindp[0][1], mindp[0][2]) + game[i][2];

		maxdp[0][0] = maxdp[1][0];
		maxdp[0][1] = maxdp[1][1];
		maxdp[0][2] = maxdp[1][2];
		
		mindp[0][0] = mindp[1][0];
		mindp[0][1] = mindp[1][1];
		mindp[0][2] = mindp[1][2];

	} 
 
	cout << max(maxdp[0][0], max(maxdp[0][1], maxdp[0][2]));
	cout << " " << min(mindp[0][0], min(mindp[0][1], mindp[0][2]));
}