#include <stdio.h>

int max(a,b){return (a>b ? a : b);}

int main() {
	int arr[1001]={0},dp[1001] = {0};
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) {
		scanf("%d",&arr[i]);
	}

	for(int i = 1;i<=n;i++) {
		int m=0;
		for(int j = 0;j<=i;j++) {
			if(arr[i] > arr[j] && dp[j] > m) {
					m=dp[j];
			}
		}
		dp[i] = m+1;
	}
	int m=0;
	for(int i = 1;i<=n;i++) {
		m=max(m,dp[i]);
	}
	printf("%d",m);
}