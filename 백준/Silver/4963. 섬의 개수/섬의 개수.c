#include <stdio.h>
#include <stdbool.h>

bool map[50][50] = {0};
void check(i,j,h,w){
	if(map[i][j] == false) return;
	if(i<0 || j<0 || i>=h || j>=w) return;
	map[i][j] = false;
	for(int a = -1;a<=1;a++)
		for(int b = -1;b<=1;b++)
			check(i+a,j+b,h,w);
}

int main() {
	while(true) {
		int w,h,count=0;
		scanf("%d %d",&w,&h);
		if(w==0 && h==0) break;
		for(int i = 0;i<h;i++) {
			for(int j = 0;j<w;j++) {
				int n; scanf("%d",&n);
				map[i][j] = n;
			}
		}
		for(int i = 0;i<h;i++) {
			for(int j = 0;j<w;j++) {
				if(map[i][j] == false) continue;
				check(i,j,h,w);
				count++;
			}
		}
		printf("%d\n",count);
	}
}
