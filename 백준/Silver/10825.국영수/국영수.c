#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[11];
	int korScore;
	int mathScore;
	int engScore;
} student;

int c(const void *a,const void *b) {
	student tmpa = *(student*)a;
	student tmpb = *(student*)b;

	if(tmpa.korScore>tmpb.korScore) return -1;
	else if(tmpa.korScore<tmpb.korScore) return 1;
	else if(tmpa.korScore==tmpb.korScore){
		if(tmpa.engScore>tmpb.engScore) return 1;
		else if(tmpa.engScore<tmpb.engScore) return -1;
		else if(tmpa.engScore==tmpb.engScore){
			if(tmpa.mathScore>tmpb.mathScore) return -1;
			else if(tmpa.mathScore<tmpb.mathScore) return 1;
			else if(tmpa.mathScore==tmpb.mathScore){
				return strcmp(tmpa.name,tmpb.name);
			}
		}
	}	return 0;
}

int main() {
	int n; scanf("%d",&n);
	student s[100000];
	for(int i = 0;i<n;i++) {
		scanf("%s",s[i].name);
		scanf("%d %d %d",&s[i].korScore,&s[i].engScore,&s[i].mathScore);
	}
	qsort(s,n,sizeof(student),c);
	for(int i = 0;i<n;i++) {
		printf("%s\n",s[i].name);
	}
}