#include <iostream>
#include <queue>
using namespace std;


int main() {
	int n,k,time=0;
	cin >> n >> k;
	bool visited[100001]={};
	queue<int>q;
	q.push(n);
	while(true) {
		int n = q.size();
		for(int i =0;i<n;i++) {
			int a = q.front();
			visited[a] = true;
			if(a==k){
				cout << time;
				return 0;
			}
			q.pop();
			if(a+1<100001){
				if(!visited[a+1])
					q.push(a+1);
			}
			if(a*2<100001) {
				if(!visited[a*2])
					q.push(a*2);
			}
			if(a>0) {
				if(!visited[a-1])
					q.push(a-1);
			}
		}
		time++;
	}
}