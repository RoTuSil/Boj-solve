#include <stdio.h>
#include <string.h>
int main(){
	char str[1000003] = " ";
	int i, cnt = 0, length = 0;
	gets(str);
	length = strlen(str);
	for(i = 0; i < length; i++){
		if(str[i] == ' ')
			cnt++;	
	}
	if(str[0] == ' ')
		cnt--;
	if (str[length - 1] == ' ')
		cnt--;
	printf("%d", cnt + 1);
}