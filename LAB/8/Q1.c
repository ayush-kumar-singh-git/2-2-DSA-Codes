#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int sz = 0;
int K;

void swap(int* a, int* b);
void heapifyUp(int idx);
void heapifyDown(int idx);
void insert(int val);
void removeMin();

int main()
{
    int n;
    scanf("%d %d", &K, &n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        if(sz<K){
            insert(x);
        }else if(x>heap[0]){
            removeMin();
            insert(x);
        }
        if(sz<K) printf("-1 ");
        else printf("%d ", heap[0]);
    }
    return 0;
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void heapifyUp(int idx){
    if(idx<=0) return;
    int parent = (idx-1)/2;
    if(heap[parent]>heap[idx]){
        swap(&heap[parent], &heap[idx]);
        heapifyUp(parent);
    }
    return;
}

void heapifyDown(int idx){
    if(2*idx+1>=sz) return;
    int left = 2*idx + 1;
    int right = 2*idx +2;
    int smallest = left;
    if(right < sz && heap[right]< heap[left]) smallest = right;
    if(heap[idx]>heap[smallest]){
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(smallest);
    }
    return;
}

void insert(int val){
    heap[sz++] = val;
    heapifyUp(sz-1);
}

void removeMin(){
    heap[0] = heap[sz-1];
    sz--;
    heapifyDown(0);
}
