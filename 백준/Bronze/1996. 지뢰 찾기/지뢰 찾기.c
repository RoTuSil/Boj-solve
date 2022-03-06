#include <stdio.h>

char map[1000][1001];
int mapC[1000][1000];
int n;
void check(i,j){
	if(map[i][j] == '.') return;
	if(map[i][j] >= '0' && map[i][j] <= '9') {
		for(int k = -1;k<=1;k++) {
			for(int l = -1;l<=1;l++) {
				if(k==0 && l==0) continue;
				if(i+k<0 || i+k>=n || j+l<0 || j+l>=n) continue;
				mapC[i+k][j+l] += map[i][j]-'0';
			}
		}
	}
}

int main() {
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%s",map[i]);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			check(i,j);
	
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			if(map[i][j] >= '0' && map[i][j] <= '9') mapC[i][j] = -1;
		
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(mapC[i][j] == -1) printf("*");
			else if(mapC[i][j]>=10) printf("M");
			else printf("%d",mapC[i][j]);
		}printf("\n");
	}
}