#include <stdio.h>
#include <stdlib.h>
int c(const void *a,const void *b){return *(int*)a-*(int*)b;}

int countH = 0;
char ch[25][26] = {0};
void check(i,j,n) {
	if(i<0 || j<0 || i>=n || j>=n) return;
	if(ch[i][j] == '0') return;
	ch[i][j] = '0';
	countH++;
	check(i+1,j,n);
	check(i,j+1,n);
	check(i-1,j,n);
	check(i,j-1,n);
}

int main() {
	int arr[700];
	int n,countD=0;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%s",ch[i]);
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(ch[i][j] == '1') {
				check(i,j,n);
				arr[countD] = countH;
				countH=0;
				countD++;
			}
		}
	}
	qsort(arr,countD,sizeof(int),c);
	printf("%d\n",countD);
	for(int i = 0;i<countD;i++)
		printf("%d\n",arr[i]);
		
}