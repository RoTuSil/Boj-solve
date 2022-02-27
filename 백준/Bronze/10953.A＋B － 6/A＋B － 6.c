#include <stdio.h>
int main() {
	char ch[4];
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) {
		scanf("%s",ch);
		printf("%d\n",(ch[0]-'0')+(ch[2]-'0'));
	}
}