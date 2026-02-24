// can be optimized but who cares
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct Pair_t{
    int s;
    int u;
}Pair;
Pair heap[MAX];
int sz = 0;

void swap(Pair* a, Pair* b){
    Pair t = *a;
    *a = *b;
    *b = t;
    return;
}

void heapifyUp(int idx){
    if(idx<=0) return;
    int parent = (idx-1)/2;
    if(heap[parent].s> heap[idx].s){
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
    if(r<sz && heap[r].s<heap[l].s) m=r;
    if(heap[idx].s>heap[m].s){
        swap(&heap[idx], &heap[m]);
        heapifyDown(m);
    }
    return;
}

void insert(int x, int y){
    heap[sz].s = x;
    heap[sz].u=y;
    sz++;
    heapifyUp(sz-1);
}

Pair* pullMin(){
    if(sz==0) return NULL;
    Pair* ans = malloc(sizeof(Pair));
    ans->s = heap[0].s;
    ans->u = heap[0].u;
    heap[0] = heap[--sz];
    heapifyDown(0);
    return ans;
}

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n2;i++){
        scanf("%d", &b[i]);
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            insert(a[i]+b[j], a[i]);
        }
    }
    int k;
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        Pair* p = pullMin();
        printf("%d %d\n", p->u, p->s-p->u);
    }
    return 0;
}

