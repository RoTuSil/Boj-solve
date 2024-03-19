#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int stone[100001];

int main() {
	int n, start;
	int count = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stone[i];
	}
	cin >> start;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		int front = current + stone[current];
		int back = current - stone[current];

		if (front <= n) {
			if (!visited[front]) {
				q.push(front);
				visited[front] = true;
				count++;
			}
		}
		if(back >= 1){
			if (!visited[back]) {
				q.push(back);
				visited[back] = true;
				count++;
			}
		}
	}
	cout << count;
}