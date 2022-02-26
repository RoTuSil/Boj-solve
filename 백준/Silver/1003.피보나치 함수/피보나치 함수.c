#include <stdio.h>

int main() {
  int n;
  scanf("%d",&n);
  int fibonacci[41]={0};
  fibonacci[1]=1;
  for(int i = 2;i<41;i++) {
    fibonacci[i]=fibonacci[i-2]+fibonacci[i-1];
  }
  int k;
  for(int i = 0;i<n;i++) {
    scanf("%d",&k);
    if(k==0) printf("1 0\n");
    else printf("%d %d\n",fibonacci[k-1],fibonacci[k]);
  }
}