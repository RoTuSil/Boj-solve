#include <stdio.h>

int sorting[1000000] = {0,};

void merge(int arr[],int start,int middle,int end) {
  int left=start;
  int right=middle+1;
  int index=start;
  while(left<=middle && right<=end) {
    if(arr[left]>=arr[right]) {
      sorting[index]=arr[right];
      right++;
    } else {
      sorting[index]=arr[left];
      left++;
    }
    index++;
  }
  if(left>middle) {
    for(int i = right;i<=end;i++) {
      sorting[index]=arr[i];
      index++;
    }
  } else {
    for(int i = left;i<=middle;i++) {
      sorting[index]=arr[i];
      index++;
    }
  }
  for(int i = start;i<=end;i++) {
    arr[i]=sorting[i];
  }
}

void mergeSort(int arr[],int start,int end) {
  if(start<end) {
    int middle=(start+end)/2;
    mergeSort(arr,start,middle);
    mergeSort(arr,middle+1,end);
    merge(arr,start,middle,end);
  }
}

int main() {
  int n,arr[1000000];
  scanf("%d",&n);
  for(int i = 0;i<n;i++) {
    scanf("%d",&arr[i]);
  }
  mergeSort(arr,0,n-1);

  for(int i = 0;i<n;i++) {
    printf("%d\n",arr[i]);
  }
}