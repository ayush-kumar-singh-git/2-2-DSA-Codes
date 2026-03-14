#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int d;
    int r;
}Node;

void swapNode(Node* a, Node* b){
    Node t = *a;
    *a = *b;
    *b = t;
    return;
}

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

    if(heap[idx] <= heap[minm]) return;

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

int compare(Node a, Node b){
    if(a.d < b.d) return 1;
    else if(a.d > b.d) return 0;
    return a.r >= b.r;
}

void sort(Node* list, int n){
    int swapped = 1;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(!compare(list[i], list[i+1])){
                swapped = 1;
                swapNode(&list[i], &list[i+1]);
            }
        }
    }while(swapped);
}

int main()
{
    int n;
    scanf("%d", &n);
    Node list[n];
    for(int i=0;i<n;i++){
        scanf("%d %d", &list[i].d, &list[i].r);
    }
    sort(list, n);
    int heap[10000];
    int sz = 0;
    for(int i=0;i<n;i++){
        if(sz < list[i].d){
            insert(heap,&sz,list[i].r);
        }
        else if(heap[0] < list[i].r){
            pullRoot(heap,&sz);
            insert(heap,&sz,list[i].r);
        }
    }
    int ans=0;
    for(int i=0;i<sz;i++){
        ans+=heap[i];
    }
    printf("%d\n",ans);
    return 0;
}


