#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	int z;
} Point;

int m,n,h,size = 0;
int s=0,e=0;
int board[100][100][100] = {0};
Point *q;

void check(x,y,z) {
	if(x<0 || x>=m || y<0 || y>=n || z<0 || z>=h) return;
	if(board[z][y][x] !=0) return;
	board[z][y][x] = 1;
	q[e].x = x;
	q[e].y = y;
	q[e].z = z;
	e++; size--;
}

int main() {
	int days = 0;
	scanf("%d %d %d",&m,&n,&h);
	size = m*n*h;
	q = (Point*)malloc(sizeof(Point)*n*m*h);
	for(int k = 0;k<h;k++) {
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<m;j++) {
				scanf("%d",&board[k][i][j]);
				if(board[k][i][j] != 0) size--;
				if(board[k][i][j] == 1) {
					q[e].x = j;
					q[e].y = i;
					q[e].z = k;
					e++;
				}
			}
		}
	}

	while(s<e) {
		int start = s;
		int end = e;
		for(int i = start;i<end;i++) {
			check(q[i].x-1,q[i].y,q[i].z);
			check(q[i].x+1,q[i].y,q[i].z);
			check(q[i].x,q[i].y+1,q[i].z);
			check(q[i].x,q[i].y-1,q[i].z);
			check(q[i].x,q[i].y,q[i].z+1);
			check(q[i].x,q[i].y,q[i].z-1);
			s++;
		}
		days++;
	}

	if(size == 0) {
		printf("%d",days-1);
	} else printf("-1");	
}