#include <iostream>
using namespace std;

typedef struct {
	int i;
	int j;
} Point;

int n, m, s = 0, e = 1;
int length[100][100] = {1};
Point q[10000];
string* board;
bool visited[100][100] = {false};

void check(int i, int j,int len) {
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (board[i][j] == '0') return;
	if (visited[i][j]) return;
	visited[i][j] = true;
	length[i][j] = len+1;
	q[e++] = { i,j };
}

int main() {
	cin >> n >> m;
	board = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	q[0] = { 0,0 };
	visited[0][0] = true;
	while (s < e) {
		int start = s;
		int end = e;
		for (int i = start; i < end; i++) {
			if (visited[n - 1][m - 1]) {
				cout << length[n-1][m-1];
				return 0;
			}
			s++;
			check(q[i].i + 1, q[i].j,length[q[i].i][q[i].j]);
			check(q[i].i - 1, q[i].j,length[q[i].i][q[i].j]);
			check(q[i].i, q[i].j + 1,length[q[i].i][q[i].j]);
			check(q[i].i, q[i].j - 1,length[q[i].i][q[i].j]);
		}
	}
}