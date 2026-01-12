#include <stdio.h>
#include <stdlib.h>

void rotate(int* a, int l, int r){
    while(l<r){
        int t = a[l];
        a[l]=a[r];
        a[r]=t;
        l++;
        r--;
    }
    return;
}

void rotateLeft(int* arr,int n, int k){
    k = k%n;
    if(k==0) return;
    rotate(arr,0,k-1);
    rotate(arr,k, n-1);
    rotate(arr, 0, n-1);
    return;
}

void rotateRight(int* arr,int n, int k){
    k = k%n;
    if(k==0) return;
    rotate(arr,n-k,n-1);
    rotate(arr,0, n-k-1);
    rotate(arr, 0, n-1);
    return;
}


void printArr(int* a, int n){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
   int n;
   scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    int D,K;
    scanf("%d %d", &D, &K);
    if(D==0){
        rotateLeft(arr,n,K);
    }else{
        rotateRight(arr,n,K);
    }
    printArr(arr,n);
    return 0;
}
