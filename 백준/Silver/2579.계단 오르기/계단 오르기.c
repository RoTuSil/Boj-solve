#include <stdio.h>

int arr[301]={0},dp[301]={0};
int max(a,b) {return (a>b ? a : b);}
int main() {
	int n;scanf("%d",&n);
	for(int i = 1;i<=n;i++) 
		scanf("%d",&arr[i]);
	dp[1] = arr[1];
	dp[2] = arr[1]+arr[2];
	for(int i = 3;i<=n;i++) {
		dp[i] = max(dp[i-2]+arr[i],arr[i-1]+dp[i-3]+arr[i]);
	}
	printf("%d\n",dp[n]);
}