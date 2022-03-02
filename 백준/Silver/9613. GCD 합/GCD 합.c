#include <stdio.h>

int gcd(a,b) {
	int r = a>b ? a%b : b%a;
	if(r==0)return (a>b ? b : a);
	else return gcd((a>b ? b : a),r);
}
int main() {
	int n;scanf("%d",&n);
	for(int i = 0;i<n;i++) {
		int m;scanf("%d",&m);
		int arr[100];
		for(int j = 0;j<m;j++)
			scanf("%d",&arr[j]);
		long sum = 0;
		for(int j = 0;j<m;j++)
			for(int k = j+1;k<m;k++)
				sum+=gcd(arr[j],arr[k]);	
		printf("%ld\n",sum);
	}
}