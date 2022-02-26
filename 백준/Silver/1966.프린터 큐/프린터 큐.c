#include <stdio.h>
int main() {
	int t;scanf("%d",&t);
	for(int i = 0;i<t;i++) {
		int n,m,arr[11000]={0},o=1;
		int start=0,end;
		scanf("%d %d",&n,&m);
		end=n;
		for(int j = 0;j<n;j++)
			scanf("%d",&arr[j]);

		for(;;) {
			int isBigger = 0;
			for(int j = start;j<end;j++) {
				if(arr[start]<arr[j]) {
					isBigger = 1;
					break;
				}
			}
			if(isBigger) {
				if(start==m) m=end;
				arr[end++] = arr[start++];
			} else{
				if(start==m) {
					printf("%d\n",o);
					break;
				}
				start++;
				o++;
			}
		}
		
	}
}