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

    if(2*idx+2<*sz && heap[2*idx+2]> heap[minm]){
        minm = 2*idx+2;
    }

    if(heap[idx] >= heap[minm]) return;

    swap(&heap[minm], &heap[idx]);
    heapifyDown(heap, sz, minm);
}

void heapifyUp(int* heap, int* sz, int idx){
    if(idx == 0) return;
    if(heap[idx] < heap[(idx-1)/2]) return;
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
    int n,k;
    scanf("%d %d", &n, &k);
    int a[26]={0};
    for(int i=0;i<n;i++){
        char c;
        scanf(" %c", &c);
        a[c-'A']++;
    ;}
    int heap[10000];
    int sz = 0;
    for(int i=0;i<26;i++){
        if(a[i]) insert(heap, &sz, a[i]);
    }
    int ans = 0;
    while(sz > 0){
        ans++;
        int curr = pullRoot(heap, &sz);
        curr--;
        int temp[10000];
        int x = 0;
        for(int i=0;i<k;i++){
        if(curr==0 && sz==0){
            int ok = 1;
            for(int j=0;j<x;j++){
                if(temp[j]!=0) ok = 0;
            }
            if(ok){
                printf("%d\n", ans);
                return 0;
                }
            }
        ans++;
        if(sz!=0){
            int cur = pullRoot(heap, &sz);
            temp[x++] = cur-1;
        }
    }       
    if(curr!=0) insert(heap, &sz, curr);
        for(int i=0;i<x;i++)
            if(temp[i]!=0)
                insert(heap, &sz, temp[i]);
    }
    printf("%d\n", ans);
    return 0;
}

