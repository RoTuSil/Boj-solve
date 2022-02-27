#include <stdio.h>
int main() {
	int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int m,d,days=0;
	char dayName[7][4] = {
	"MON","TUE","WED","THU","FRI","SAT","SUN"
	};
	scanf("%d %d",&m,&d);
	for(int i = 1;i<m;i++)
		days+=daysInMonth[i];
	days+=d;
	printf("%s",dayName[(days-1)%7]);
}