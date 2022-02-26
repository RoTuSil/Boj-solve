#include <stdio.h> 
#include <stdbool.h>

bool arr[1001][1001]={0};
int stack[1001];
int queue[2001];
bool visited[1001]={0};

void dfs(int n,int m) {
	for(int i = 1;i<=m;i++) {
		if(arr[n][i] == true && visited[i] == false ){
			printf("%d ",i);
			visited[i]=true;
			dfs(i,m);
		}
	}

}


int main() {
	int n,m,s,idx=0,f=0,e=0;
	scanf("%d %d %d",&n,&m,&s);
	stack[idx++] = s;
	queue[e++] = s;
	visited[s] = true;
	for(int i = 0,n1,n2;i<m;i++) {
		scanf("%d %d",&n1,&n2);
		arr[n1][n2] = true;
		arr[n2][n1] = true;
	}
	//DFS
	printf("%d ",s);
	dfs(s,n);
//clear visited array
    for(int i = 1;i<=n;i++) visited[i] = false;
    	//BFS
    	visited[s] = true;
    	printf("\n%d ",s);
    	while(f<e) {
    		int now = queue[f++];
    		for(int i = 0;i<=n;i++) {
    			if(arr[now][i] == true && visited[i] == false) {
    				printf("%d ",i);
    				queue[e++] = i;
    				visited[i] = true;
    		}
    	}
	}
}