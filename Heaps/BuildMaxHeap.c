#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
void heapify(int* a, int n, int i);
void buildMaxHeap(int* a, int n);
void printArr(int* a, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    buildMaxHeap(a,n);
    printArr(a,n);
    return 0;
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void heapify(int* a, int n, int i){
    int maxm = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && a[left] > a[maxm]) maxm = left;
    if(right < n && a[right] > a[maxm]) maxm = right;
    if(maxm != i){
        swap(&a[maxm], &a[i]);
        heapify(a,n,maxm);
    }
    return;
}

void buildMaxHeap(int* a, int n){
    for (int i = (n/2) - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void printArr(int* a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}
