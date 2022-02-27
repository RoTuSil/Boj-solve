#include <stdio.h>
int max(a,b) {return (a>b ? a : b);}
int arr[10001]={0},dp[10001]={0};

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		scanf("%d",&arr[i]);
	dp[1] = arr[1];
	dp[2] = arr[1]+arr[2];
	for(int i = 0;i<=n;i++) {
		dp[i] = max(dp[i-2]+arr[i],max(dp[i-3]+arr[i-1]+arr[i],dp[i-1]));
	}
	printf("%d",dp[n]);
}