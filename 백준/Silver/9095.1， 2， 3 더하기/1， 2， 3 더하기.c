#include <stdio.h> 

int arr[11] = {0,1,2,4};


int getKinds(int n) {
  if(arr[n]==0) arr[n]=getKinds(n-1)+getKinds(n-2)+getKinds(n-3);
  return arr[n];
}

int main() {
  int n;
  scanf("%d",&n);
  for(int i = 0;i<n;i++) {
    int k;
    scanf("%d",&k);
    printf("%d\n",getKinds(k));
  }
}