#include <stdio.h> 
int main() {
	long long arr[90][2] = {{0,1}};
	int n;
	scanf("%d",&n);
	for(int i = 1;i<n;i++) {
		arr[i][0] += (arr[i-1][0] + arr[i-1][1]);
		arr[i][1] += arr[i-1][0];
	}
	printf("%lld",arr[n-1][0]+arr[n-1][1]);
}