#include <stdio.h>
int main() {
	char ch[101];
	while(scanf(" %[^\n]",ch)!=EOF) {
		printf("%s\n",ch);
	}
}