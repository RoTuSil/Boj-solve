#include <iostream>
#include <vector>
using namespace std;

bool visited[26];
string board[20];
int r, c, length = 0, maxLength = 0;

void search(int i, int j) {
	if (i < 0 || j < 0 || i >= r || j >= c) return;
	if (visited[board[i][j] - 'A']) return;
	visited[board[i][j] - 'A'] = true;
	length++;
	maxLength = max(maxLength, length);
	search(i + 1, j);
	search(i - 1, j);
	search(i, j + 1);
	search(i, j - 1);
	visited[board[i][j] - 'A'] = false;
	length--;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> board[i];
	search(0, 0);
	cout << maxLength;
}