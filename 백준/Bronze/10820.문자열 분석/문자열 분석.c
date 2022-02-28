#include <stdio.h>
#include <string.h>
int main() {
	char arr[101];
	while(gets(arr)) {
		int l = strlen(arr);
		int LC=0,UC=0,n=0,space=0;
		for(int i = 0;i<l;i++) {
			if(arr[i]>='A' && arr[i]<='Z') UC++;
			else if(arr[i] >= 'a' && arr[i] <= 'z') LC++;
			else if(arr[i] >= '0' && arr[i] <= '9') n++;
			else if(arr[i] == ' ') space++;
		}
		printf("%d %d %d %d\n",LC,UC,n,space);
		arr[0] = 0;
	}
}