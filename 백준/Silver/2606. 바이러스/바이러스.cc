#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n,m;
	int count = 0;
	bool visited[101] = {false};
	bool arr[101][101] = {false};
	queue<int> q;
	cin >> n >> m;
	for(int i =0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}
	visited[1] = true;
	q.push(1);
	while(!q.empty()) {
		int idx = q.front();
		q.pop();
		for(int i =1;i<=n;i++) {
			if(arr[idx][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				count++;
			}
		}
	}
	cout << count;
}