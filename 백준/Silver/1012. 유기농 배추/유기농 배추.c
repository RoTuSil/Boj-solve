#include <stdio.h>
#include <stdbool.h>

bool planted[50][50];

void check(i,j,m,n) {
	if(planted[i][j] == false) return;
	if(i<0 || j<0 || i>=n || j>=m) return;
	planted[i][j] = false;
	check(i+1,j,m,n);
	check(i,j+1,m,n);
	check(i,j-1,m,n);
	check(i-1,j,m,n);
	return;
}

int main() {
	int t,m,n,k,count;
	scanf("%d",&t);
	for(int i = 0;i<t;i++) {
		count = 0;
		//reset array
		for(int j = 0;j<50;j++)
			for(int k = 0;k<50;k++)
				planted[j][k] = false;

		scanf("%d %d %d",&m,&n,&k);
		for(int j = 0;j<k;j++) {
			int x,y;
			scanf("%d %d",&x,&y);
			planted[y][x] = true;
		}
		//check
		for(int j = 0;j<n;j++) {
			for(int k = 0;k<m;k++) {
				if(planted[j][k] == true) {
					check(j,k,m,n);
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
}