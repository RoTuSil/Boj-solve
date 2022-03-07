#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int i;
	int j;
}point2D;

int main() {
	int board[1000][1000]={0};
	int s=0,e=0;
	int n,m;
	int size,days =-1;
	point2D *q;
	scanf("%d %d",&m,&n);
	size = n*m;
	q = (point2D*)malloc(sizeof(point2D)*size);
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			scanf("%d",&board[i][j]);
			if(board[i][j] == 1) {
				q[e].i = i;
				q[e].j = j; e++;
			}
			if(board[i][j] != 0) size--;
		}
	}
	while(s<e) {
		int start = s;
		int end = e;
		for(int i = start;i<end;i++) {
			s++;
			
			if(q[i].i+1<n) {
				if(board[q[i].i+1][q[i].j] == 0) {
					board[q[i].i+1][q[i].j] = 1;	
					q[e].i = q[i].i+1;
					q[e].j = q[i].j;
					e++;size--;
				} 
			}
			if(q[i].i>0) {
				if(board[q[i].i-1][q[i].j] == 0) {
					board[q[i].i-1][q[i].j] = 1;	
					q[e].i = q[i].i-1;
					q[e].j = q[i].j;
					e++;size--;
				}	
			}
			if(q[i].j+1<m) {
				if(board[q[i].i][q[i].j+1] == 0) {
					board[q[i].i][q[i].j+1] = 1;	
					q[e].i = q[i].i;
					q[e].j = q[i].j+1;
					e++;size--;
				}					
			}
			if(q[i].j>0) {
				if(board[q[i].i][q[i].j-1] == 0) {
					board[q[i].i][q[i].j-1] = 1;	
					q[e].i = q[i].i;
					q[e].j = q[i].j-1;
					e++;size--;
				}
			}
		}
		days++;
	}
	
	if(size==0) printf("%d",days);
	else printf("-1");
}