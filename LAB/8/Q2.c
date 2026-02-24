#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int sz = 0;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void heapifyUp(int idx){
    if(idx<=0) return;
    int parent = (idx-1)/2;
    if(heap[parent]> heap[idx]){
        swap(&heap[parent], &heap[idx]);
        heapifyUp(parent);
    }
    return;
}

void heapifyDown(int idx){
    if(2*idx+1>=sz) return;
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    int m = l;
    if(r<sz && heap[r]<heap[l]) m=r;
    if(heap[idx]>heap[m]){
        swap(&heap[idx], &heap[m]);
        heapifyDown(m);
    }
    return;
}

void insert(int x){
    heap[sz] = x;
    sz++;
    heapifyUp(sz-1);
}

int pullMin(){
    if(sz==0) return 0;
    int val = heap[0];
    heap[0] = heap[--sz];
    heapifyDown(0);
    return val;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        insert(temp);
    }
    int totalCost=0;
    int a,b;
    while(sz>1){
        a=pullMin();
        b=pullMin();
        totalCost+=(a+b);
        insert(a+b);
    }
    printf("%d\n", totalCost);
    return 0;
}
