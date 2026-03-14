#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int val;
    int i;
    int j;
}Node;

void swap(Node* a, Node* b){
    Node t = *a;
    *a = *b;
    *b = t;
    return;
}

int cmp(Node a, Node b){
    return a.val<=b.val;
}

void heapifyDown(Node* heap, int* sz, int idx){
    if(idx >= *sz-1) return;
    if(2*idx+1 >= *sz) return;

    int minm = 2*idx+1;

    if(2*idx+2<*sz && cmp(heap[2*idx+2], heap[minm])){
        minm = 2*idx+2;
    }

    if(cmp(heap[idx], heap[minm])) return;

    swap(&heap[minm], &heap[idx]);
    heapifyDown(heap, sz, minm);
}

void heapifyUp(Node* heap, int* sz, int idx){
    if(idx == 0) return;
    if(!cmp(heap[idx], heap[(idx-1)/2])) return;
    swap(&heap[idx], &heap[(idx-1)/2]);
    heapifyUp(heap, sz, (idx-1)/2);
}

void insert(Node* heap, int* sz, int x, int i, int j){
    Node newNode = {x,i,j};
    heap[*sz] = newNode;
    heapifyUp(heap, sz, *sz);
    *sz = *sz+1;
}

Node pullRoot(Node* heap, int* sz){
    Node ans = heap[0];
    heap[0] = heap[*sz-1];
    *sz = (*sz)-1;
    heapifyDown(heap, sz, 0);
    return ans;
}

int max(int a, int b){ return a>b?a:b; }

int main()
{
    int K;
    scanf("%d", &K);
    int N[K];
    int a[K][10000];
    for(int i=0;i<K;i++){
        scanf("%d", &N[i]);
        for(int j=0; j<N[i]; j++){
            scanf("%d", &a[i][j]);
        }
    }
    Node heap[10000];
    int sz = 0;
    int curr_max = -10000;
    for(int i=0;i<K;i++){
        insert(heap, &sz, a[i][0], i, 0);
        curr_max = max(curr_max, a[i][0]);
    }
    int l = heap[0].val,r=curr_max;
    int ans = curr_max - heap[0].val;
    while(1){
        Node cur = pullRoot(heap, &sz);
        int ni = cur.i;
        int nj = cur.j;
        nj++;
        if(nj >= N[ni]) break;
        insert(heap, &sz, a[ni][nj], ni, nj);
        curr_max = max(curr_max, a[ni][nj]);
        int curRange = curr_max - heap[0].val;
        if(curRange < ans || (curRange == ans && heap[0].val < l)){
            ans = curRange;
            l = heap[0].val;
            r = curr_max;
        }    
    }
    printf("%d %d\n", l,r);
    return 0;
}

