#include <stdio.h>
int main() {
	int arr[1000][10]={0};
	for(int i = 0;i<10;i++) arr[0][i] = 1;
	int n; scanf("%d",&n);
	for(int i = 1;i<n;i++) {
		arr[i][0] += arr[i-1][0];
		for(int j = 1;j<10;j++) {
			for(int k = 0;k<=j;k++)
				arr[i][j] += arr[i-1][k];
			arr[i][j]%=10007;
		}
	}
	int sum = 0;
	for(int i = 0;i<10;i++) sum+=arr[n-1][i];
	sum%=10007;
	printf("%d",sum);
}