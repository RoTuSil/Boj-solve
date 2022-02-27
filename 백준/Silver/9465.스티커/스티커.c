#include <stdio.h>
#include <stdlib.h>

int max(int a,int b) {
	return (a>b ? a : b);
}
int **arr;
int **dp;

int main() {
	int t;
	scanf("%d",&t);
	for(int i = 0;i<t;i++) {
		int n;
		scanf("%d",&n);
		arr = (int**)malloc(sizeof(int*)*2);
		dp = (int**)malloc(sizeof(int*)*2);
		for(int j = 0;j<2;j++) {
			arr[j] = (int*)malloc(sizeof(int)*(n+1)); 
			dp[j] =  (int*)malloc(sizeof(int)*(n+1)); 
		}

		arr[0][0] = 0;
		arr[1][0] = 0;
		for(int j = 0;j<2;j++)
			for(int k = 1;k<=n;k++)
				scanf("%d",&arr[j][k]);

		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		
		for(int j = 2;j<=n;j++) {
			dp[0][j] = max(dp[1][j-1],dp[1][j-2])+arr[0][j];
			dp[1][j] = max(dp[0][j-1],dp[0][j-2])+arr[1][j];
		}
		printf("%d\n",max(dp[0][n],dp[1][n]));
		free(arr);
		free(dp);
	}
}