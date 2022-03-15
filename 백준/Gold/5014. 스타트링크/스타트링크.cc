#include <iostream>
#include <queue>
using namespace std;
int main() {
	int floor, start, goal, up, down;
	int buttonPressed = 0;
	bool visited[1000001] = {};
	queue<int> q;
	cin >> floor >> start >> goal >> up >> down;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (now == goal) {
				cout << buttonPressed;
				return 0;
			}
			if (now + up <= floor) {
				if (!visited[now + up]) {
					q.push(now + up);
					visited[now + up] = true;
				}
			}
			if (now - down > 0) {
				if (!visited[now - down]) {
					q.push(now - down);
					visited[now - down] = true;
				}
			}
		}
		buttonPressed++;
	}
	cout << "use the stairs";
}