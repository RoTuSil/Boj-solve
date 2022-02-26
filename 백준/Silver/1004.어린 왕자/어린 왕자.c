#include <stdio.h>
#include <stdlib.h>

struct pointC {
	int x;
	int y;
	int r;
};

int getLengthSqr(x1,y1,x2,y2) {
	int a = x2-x1;
	int b = y2-y1;
	return a*a+b*b;
}

int main() {
	int n,x1,y1,x2,y2;
	struct pointC* a;
	scanf("%d",&n);
	for(int k = 0, t; k < n; k++) {
		int flyInAndOut = 0;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		scanf("%d",&t);
		a = (struct pointC*)malloc(sizeof(struct pointC)*t);
		for(int i = 0;i<t;i++) {
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].r);
			if((getLengthSqr(a[i].x,a[i].y,x1,y1) < a[i].r * a[i].r) !=
				(getLengthSqr(a[i].x,a[i].y,x2,y2) < a[i].r * a[i].r)) {
				flyInAndOut++;
			}
		}
		printf("%d\n",flyInAndOut);
	free(a);
	}
}