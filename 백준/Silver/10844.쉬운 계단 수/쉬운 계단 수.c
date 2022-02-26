#include <stdio.h> 
int main() {
	int arr[100][10] = {0,1,1,1,1,1,1,1,1,1};
	int n,m=1000000000;
	scanf("%d",&n);
	for(int i = 1;i<n;i++) {
		arr[i][0] += arr[i-1][1];
		arr[i][9] += arr[i-1][8];
		for(int j = 1;j<9;j++) {
			arr[i][j] += (arr[i-1][j-1] + arr[i-1][j+1])%m;
		}
	}
	int sum=0;
	for(int i = 0;i<10;i++) {
		sum+=arr[n-1][i];
		sum%=m;
	}
	printf("%d",sum);
	
}