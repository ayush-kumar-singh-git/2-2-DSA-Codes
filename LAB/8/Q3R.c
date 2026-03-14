/*
 * Type  0 : min Heap
 * Type 1 : max Heap
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void heapifyDown(int* heap, int* sz, int idx, int type){
    if(type==0){
        if(idx >= *sz-1) return;
        if(2*idx+1 >= *sz) return;

        int minm = 2*idx+1;

        if(2*idx+2<*sz && heap[2*idx+2]< heap[minm]){
            minm = 2*idx+2;
        }

        if(heap[idx] <= heap[minm]) return;

        swap(&heap[minm], &heap[idx]);
        heapifyDown(heap, sz, minm, type);
    }else{
        if(idx >= *sz-1) return;
        if(2*idx+1 >= *sz) return;

        int maxm = 2*idx+1;

        if(2*idx+2<*sz && heap[2*idx+2]> heap[maxm]){
            maxm = 2*idx+2;
        }

        if(heap[idx] <= heap[maxm]) return;

        swap(&heap[maxm], &heap[idx]);
        heapifyDown(heap, sz, maxm, type);
    }
}

void heapifyUp(int* heap, int* sz, int idx, int type){
    if(type == 0){
        if(idx == 0) return;
        if(heap[idx] >= heap[(idx-1)/2]) return;
        swap(&heap[idx], &heap[(idx-1)/2]);
        heapifyUp(heap, sz, (idx-1)/2, type);
    }else if(type==1){
        if(idx == 0) return;
        if(heap[idx] <= heap[(idx-1)/2]) return;
        swap(&heap[idx], &heap[(idx-1)/2]);
        heapifyUp(heap, sz, (idx-1)/2, type);
    }
}

void insert(int* heap, int* sz, int x, int type){
    heap[*sz] = x;
    heapifyUp(heap, sz, *sz, type);
    *sz = *sz+1;
}

int pullRoot(int* heap, int* sz, int type){
    int ans = heap[0];
    heap[0] = heap[*sz-1];
    *sz = (*sz)-1;
    heapifyDown(heap, sz, 0, type);
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int minHeap[10000];
    int minSz = 0;
    int maxHeap[10000];
    int maxSz = 0;
    insert(minHeap, &minSz, a[0], 0);
    float av = a[0];
    printf("%.1f ",av);
    for(int i=1;i<n;i++){
        if(a[i]>minHeap[0]){
            insert(minHeap, &minSz, a[i], 0);
        }else{
            insert(maxHeap, &maxSz, a[i], 1);
        }

        if(minSz > 1+maxSz){
            int x = pullRoot(minHeap, &minSz, 0);
            insert(maxHeap, &maxSz, x, 1);
        }else if(maxSz > 1 + minSz){
            int x = pullRoot(maxHeap, &maxSz, 1);
            insert(minHeap, &minSz, x, 0);
        }

        if(maxSz > minSz){
            av = maxHeap[0];
        }else if(minSz > maxSz){
            av = minHeap[0];
        }else{
            av = maxHeap[0];
            av = (av + minHeap[0])/2;
        }

        printf("%.1f ", av);
    }
    printf("\n");
    return 0;
}

