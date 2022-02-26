#include <stdio.h>
int main() {
	int n,a,b,round=1;
	scanf("%d %d %d",&n,&a,&b);
	if(a>b) {
		int t=a;a=b;b=t;
	}
	for(;;) {
		if(a%2==1 &&a+1==b) break;
		a = a%2==1 ? (a+1)/2 : a/2;
		b = b%2==1 ? (b+1)/2 : b/2;
		round++;
	}
	printf("%d",round);
}