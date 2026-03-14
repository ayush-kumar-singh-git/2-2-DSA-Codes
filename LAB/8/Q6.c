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

int main()
{
    
    int n;
    scanf("%d",&n);

    int heap[10000];
    int sz = 0;
    int visited[100000] ={0};

    insert(heap,&sz,2);
    insert(heap,&sz,5);
    insert(heap,&sz,7);

    visited[2]=visited[5]=visited[7]=1;

    int val;

    for(int i=0;i<n;i++){

        val = pullRoot(heap,&sz);

        int a = val*2;
        int b = val*5;
        int c = val*7;

        if(a<=100000 && !visited[a]){
            insert(heap,&sz,a);
            visited[a]=1;
        }

        if(b<=100000 && !visited[b]){
            insert(heap,&sz,b);
            visited[b]=1;
        }

        if(c<=100000 && !visited[c]){
            insert(heap,&sz,c);
            visited[c]=1;
        }
    }
    printf("%d\n",val);
    return 0;
}

