#include <stdio.h>

long getNewN(int n) {
	if(n==0) return 0;
	int digit = 0;
	long nines=0;
	for(int i=n;i!=0;) {
		digit++;
		i/=10;
	}
	for(int i = 0;i<digit-1;i++) {
		nines*=10;
		nines+=9;
	}	
	return (n - nines) * digit + getNewN(nines);	
}

int main() {
	int n;
	scanf("%d",&n);
	getNewN(n);
	printf("%ld",getNewN(n));
}