#include <stdio.h>

void makeN(n,b) {
	if(n==0)return;
	makeN(n/b,b);
	if(n%b<10) printf("%d",n%b);
	else printf("%c",n%b-10+'A');
}
int main() {
	int n,b;
	scanf("%d %d",&n,&b);
	makeN(n,b);
}