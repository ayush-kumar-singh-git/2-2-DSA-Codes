#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(int* arr, int l, int r){
    while(l<r){
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }
}

void rotateLeft(int* arr, int n, int k){
    if(k==0) return;
    reverse(arr, 0, n-1);
    reverse(arr, n-k, n-1);
    reverse(arr, 0, n-k-1);
}

void rotateRight(int* arr, int n, int k){
    if(k==0) return;
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
}

int main()
{
   int n;
   scanf("%d", &n);
   int arr[n];
   for(int i=0;i<n;i++){
       scanf("%d", &arr[i]);
   }
   int D,K;
   scanf("%d %d", &D, &K);
   K= (K%n);
   if(D==0){
       rotateLeft(arr,n,K);
   }else{
       rotateRight(arr,n,K);
   }
   for(int i=0;i<n;i++){
       printf("%d ", arr[i]);
   }
   printf("\n");
    return 0;
}
