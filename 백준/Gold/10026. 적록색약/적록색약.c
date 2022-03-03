#include <stdio.h>
#include <stdbool.h>

char drawing[100][101];
bool visited[100][101] = {0};

void check(int x,int y,char color,int size) {
	if(x<0 || y<0 || x>=size || y>=size) return;
	if(visited[y][x] == true) return;
	if(drawing[y][x] == color) {
		visited[y][x] = true;
		check(x+1,y,color,size);
		check(x,y+1,color,size);
		check(x-1,y,color,size);
		check(x,y-1,color,size);
	}

	return;
}

int main() {
	int n; scanf("%d",&n);
	int countColor = 0,countCBlind = 0;
	for(int i = 0;i<n;i++)
		scanf("%s",drawing[i]);

	//count color
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(visited[i][j] == true) continue;
			if(visited[i][j] == false) countColor++;
			check(j,i,drawing[i][j],n);
		}
	}
	//reset bool array
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			visited[i][j] = false;

	//make colorblind
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			if(drawing[i][j] == 'G')drawing[i][j] = 'R';

	//count colorblind
	
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(visited[i][j] == true) continue;
			if(visited[i][j] == false) countCBlind++;
			check(j,i,drawing[i][j],n);
		}
	}
	printf("%d %d",countColor,countCBlind);
	
	
}
