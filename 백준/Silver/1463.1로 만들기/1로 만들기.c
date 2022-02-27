#include <stdio.h>

int arr[1000001]={0,0,1,1,};


int makeOne(int n) {
  if(n==1) return 0;
  if(arr[n]!=0) return arr[n];
  else {
    int i=0,min[3]={0};
    if(n%2==0) min[i++] = 1 + makeOne(n/2);
    if(n%3==0) min[i++] = 1 + makeOne(n/3);
    min[i] = 1 + makeOne(n-1);
    int m=min[0];
    if(m>min[1] && min[1] !=0) m=min[1];
    if(m>min[2] && min[2] !=0) m=min[2];
    arr[n]=m;
    return m;
  }
}

int main() {
  int n;
  scanf("%d",&n);
  printf("%d",makeOne(n));
} 