#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    int r;
    int c;
}Node;

void swap(Node* a, Node* b){
    Node t = *a;
    *a = *b;
    *b = t;
}

int cmp(Node a, Node b){
    return a.val <= b.val;
}

void heapifyDown(Node* heap, int* sz, int idx){
    if(2*idx+1 >= *sz) return;

    int minm = 2*idx+1;

    if(2*idx+2 < *sz && cmp(heap[2*idx+2], heap[minm]))
        minm = 2*idx+2;

    if(cmp(heap[idx], heap[minm])) return;

    swap(&heap[idx], &heap[minm]);
    heapifyDown(heap, sz, minm);
}

void heapifyUp(Node* heap, int* sz, int idx){
    if(idx == 0) return;

    int p = (idx-1)/2;

    if(cmp(heap[p], heap[idx])) return;

    swap(&heap[p], &heap[idx]);
    heapifyUp(heap, sz, p);
}

void insert(Node* heap, int* sz, int x, int i, int j){
    Node newNode = {x,i,j};

    heap[*sz] = newNode;
    heapifyUp(heap, sz, *sz);
    (*sz)++;
}

Node pullRoot(Node* heap, int* sz){
    Node ans = heap[0];
    heap[0] = heap[*sz-1];
    (*sz)--;
    heapifyDown(heap, sz, 0);
    return ans;
}

int main(){

    int n;
    scanf("%d",&n);

    int a[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    int k;
    scanf("%d",&k);

    Node heap[100000];
    int sz = 0;

    for(int i=0;i<n;i++)
        insert(heap,&sz,a[i][0],i,0);

    for(int i=0;i<k-1;i++){
        Node cur = pullRoot(heap,&sz);

        int x = cur.r;
        int y = cur.c;

        insert(heap,&sz,a[x][y+1],x,y+1);
    }

    printf("%d\n",heap[0].val);
}
