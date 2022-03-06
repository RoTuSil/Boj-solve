#include <stdio.h>

int main()
{
  char board[51][51];
  
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0;i<n;i++)
    {
      scanf("%s",board[i]);
    }

  
  char RowB[8] = "BWBWBWBW";
  char RowW[8] = "WBWBWBWB";
  int comp=n*m;
  int compW = 0;
  int compB = 0;
  int rowColor = 0; // 0=B 1=W
  for(int x = 0;x<n-7;x++) {
    for(int y = 0;y<m-7;y++) {
      compW=0;compB=0;
      for(int i = 0;i<8;i++)  {    
        //매 줄마다 보드 시작색 바꾸기
        if(rowColor==1) {rowColor=0;} 
          else {rowColor++;}
        for(int l = 0;l<8;l++)  {
         // printf("%c, %c ",RowW[l],board[x+i][y+l]);// 제출시 지울것
          
          if(rowColor==1 && (RowW[l] != board[x+i][y+l])) compW++;
          else if(rowColor==0 && (RowB[l] != board[x+i][y+l])) compW++;
          if(rowColor==0 && (RowW[l] != board[x+i][y+l])) compB++;
          else if(rowColor==1 && (RowB[l] != board[x+i][y+l])) compB++;
        }
        
          //printf("\n");
      }
      if(compB<compW && compB<comp) comp=compB;
      else if(compW<compB && compW<comp) comp=compW;
      else if(compW==compB && compW<comp) comp=compW;
    }
  }
printf("%d",comp);

  
}
