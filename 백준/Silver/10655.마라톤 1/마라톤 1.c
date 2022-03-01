#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
} Point;

int getDst(Point a,Point b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}
int main() {
	int n,dst=0,minDst=2147483647;
	scanf("%d",&n);
	Point cp[100000]={0};
	for(int i = 0;i<n;i++) {
		scanf("%d %d",&cp[i].x,&cp[i].y);
		if(i!=0) dst+=getDst(cp[i-1],cp[i]);
	}
	for(int i = 1;i<n-1;i++) {
		int d = dst -(getDst(cp[i-1],cp[i])+getDst(cp[i],cp[i+1]));
		d+=getDst(cp[i-1],cp[i+1]);
		if(d<minDst) minDst=d;
	}
	printf("%d",minDst);
}