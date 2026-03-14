#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void heapifyDown(int* heap, int* sz, int idx){
    if(2*idx+1 >= *sz) return;

    int minm = 2*idx+1;

    if(2*idx+2<*sz && heap[2*idx+2]> heap[minm]){
        minm = 2*idx+2;
    }

    if(heap[idx] >= heap[minm]) return;

    swap(&heap[minm], &heap[idx]);
    heapifyDown(heap, sz, minm);
}

void heapifyUp(int* heap, int* sz, int idx){
    if(idx == 0) return;
    if(heap[idx] <= heap[(idx-1)/2]) return;
    swap(&heap[idx], &heap[(idx-1)/2]);
    heapifyUp(heap, sz, (idx-1)/2);
}

void insert(int* heap, int* sz, int x){
    heap[*sz] = x;
    heapifyUp(heap, sz, *sz);
    *sz = *sz+1;
}

int pullRoot(int* heap, int* sz){
    if(*sz == 0) return -1;
    int ans = heap[0];
    heap[0] = heap[*sz-1];
    *sz = (*sz)-1;
    heapifyDown(heap, sz, 0);
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    int heap[100000];
    int sz = 0;
    for(int i = 0; i<n;i++){
        for(int j=0;j<n;j++){
            if(sz < k){
                insert(heap, &sz, a[i][j]);
            }else{
                if(heap[0] > a[i][j]){
                    pullRoot(heap, &sz);
                    insert(heap, &sz, a[i][j]);
                }
            }
        }
    }
    printf("%d \n", heap[0]);
    return 0;
}

