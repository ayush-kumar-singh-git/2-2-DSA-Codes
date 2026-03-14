#include <stdio.h>
#include <stdlib.h>

typedef struct Pair_t{
    int s;
    int u;
}Pair;

void swap(Pair* a, Pair* b){
    Pair t = *a;
    *a = *b;
    *b = t;
    return;
}

int cmp(Pair p1, Pair p2){
    // 1 if p1 before p2
    return p1.s <= p2.s;
}

void heapifyDown(Pair* heap, int* sz, int idx){
    if(2*idx+1 >= *sz) return;

    int minm = 2*idx+1;

    if(2*idx+2<*sz && cmp(heap[2*idx+2], heap[minm])){
        minm = 2*idx+2;
    }

    if(cmp(heap[idx], heap[minm])) return;

    swap(&heap[minm], &heap[idx]);
    heapifyDown(heap, sz, minm);
}

void heapifyUp(Pair* heap, int* sz, int idx){
    if(idx == 0) return;
    if(!cmp(heap[idx], heap[(idx-1)/2])) return;
    swap(&heap[idx], &heap[(idx-1)/2]);
    heapifyUp(heap, sz, (idx-1)/2);
}

void insert(Pair* heap, int* sz, int x, int y){
    Pair newPair = {x+y, x};
    heap[*sz] = newPair;
    heapifyUp(heap, sz, *sz);
    *sz = *sz+1;
}

Pair pullRoot(Pair* heap, int* sz){
    Pair ans = heap[0];
    heap[0] = heap[*sz-1];
    *sz = (*sz)-1;
    heapifyDown(heap, sz, 0);
    return ans;
}

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    int a[m], b[n];
    for(int i=0;i<m;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }
    int k;
    scanf("%d", &k);
    Pair heap[10000];
    int sz = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            insert(heap, &sz, a[i], b[j]);
        }
    }

    for(int i=0;i<k;i++){
        Pair p = pullRoot(heap, &sz);
        printf("%d %d\n", p.u, p.s-p.u);
    }
    return 0;
}

