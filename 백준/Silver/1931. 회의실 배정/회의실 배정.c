#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int start;
	int end;
}ST;

int c(const void *a,const void *b) {
	ST A = *(ST*)a;
	ST B = *(ST*)b;
	if(A.end!=B.end)
		return A.end-B.end;
	return A.start-B.start;
}

int main() {
	ST t[100000];
	int n,count=1;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d %d",&t[i].start,&t[i].end);
	qsort(t,n,sizeof(ST),c);
	ST before=t[0];
	for(int i = 1;i<n;i++) {
		if(before.end<=t[i].start){
			before = t[i];
			count++;
		}
	}
	printf("%d",count);
}