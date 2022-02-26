#include <stdio.h> 

int min(int a,int b) {
	return (a>=b ? b : a);
}
int main() {
	int n,select = -1;
	int p[1001][3];
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<3;j++)
			scanf("%d",&p[i][j]);
	for(int i = 1;i<n;i++) {
		p[i][0] +=  min(p[i-1][1],p[i-1][2]);
		p[i][1] +=  min(p[i-1][0],p[i-1][2]);
		p[i][2] +=  min(p[i-1][0],p[i-1][1]);
	}
	printf("%d",min(min(p[n-1][0],p[n-1][1]),p[n-1][2]));
}