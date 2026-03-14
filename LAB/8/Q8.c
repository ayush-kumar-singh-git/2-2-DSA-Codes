#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int h;
    int r;
    int c;
}Node;

void swap(Node* a, Node* b){
    Node t = *a;
    *a = *b;
    *b = t;
    return;
}

int cmp(Node a, Node b){
    return a.h<=b.h;
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

int main()
{
    int m,n;
    scanf(" %d %d",&m, &n);
    int a[m][n];
    int v[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
            v[i][j] = 0;
        }
    }
    Node heap[10000];
    int sz = 0;
    for(int i=0;i<n;i++){
        insert(heap, &sz, a[0][i], 0, i);
        v[0][i] = 1;
    }
    for(int i=0;i<n;i++){
        insert(heap, &sz, a[m-1][i], m-1, i);
        v[m-1][i] = 1;
    }
    for(int i=0;i<m;i++){
        insert(heap, &sz, a[i][0], i, 0);
        v[i][0] = 1;
    }
    for(int i=0;i<m;i++){
        insert(heap, &sz, a[i][n-1], i, n-1);
        v[i][n-1] = 1;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = 0;
    while(sz>0){
        Node cur = pullRoot(heap, &sz);
        for(int d=0; d<4; d++){
            int nr = cur.r + dx[d];
            int nc = cur.c + dy[d];
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
            if(v[nr][nc]) continue;
            v[nr][nc] = 1;
            int nh = a[nr][nc];
            if(cur.h > nh){
                ans += cur.h - nh;
            }
            int newh = nh > cur.h ? nh : cur.h;
            insert(heap, &sz, newh, nr, nc);
        }
    }
    printf("%d\n", ans);
    return 0;
}

