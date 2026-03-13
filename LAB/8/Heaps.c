#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void heapifyDown(int* heap, int* sz, int idx){
    if(idx >= *sz-1) return;
    if(2*idx+1 >= *sz) return;

    int minm = 2*idx+1;

    if(2*idx+2<*sz && heap[2*idx+2]< heap[minm]){
        minm = 2*idx+2;
    }

    if(heap[idx] < heap[minm]) return;

    swap(&heap[minm], &heap[idx]);
    heapifyDown(heap, sz, minm);
}

void heapifyUp(int* heap, int* sz, int idx){
    if(idx == 0) return;
    if(heap[idx] > heap[(idx-1)/2]) return;
    swap(&heap[idx], &heap[(idx-1)/2]);
    heapifyUp(heap, sz, (idx-1)/2);
}

void insert(int* heap, int* sz, int x){
    heap[*sz] = x;
    heapifyUp(heap, sz, *sz);
    *sz = *sz+1;
}

int pullRoot(int* heap, int* sz){
    int ans = heap[0];
    heap[0] = heap[*sz-1];
    *sz = (*sz)-1;
    heapifyDown(heap, sz, 0);
    return ans;
}

void inOrderTraversal(int* heap, int* sz, int idx){
    if(idx>=*sz) return;
    inOrderTraversal(heap, sz, 2*idx+1);
    printf("%d ", heap[idx]);
    inOrderTraversal(heap, sz, 2*idx+2);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int minHeap[10000];
    int sz = 0;
    for(int i=0;i<n;i++){
        insert(minHeap, &sz, a[i]);
    }
    inOrderTraversal(minHeap, &sz, 0);
    printf("\n");
    return 0;
}
