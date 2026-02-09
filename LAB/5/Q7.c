#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

int partition(int* a, int l, int r){
    int pivot = a[l];
    int left = l+1, right = r;
    while(1){
        while(left<=r && a[left]<pivot) left++;
        while(right>=l && a[right]>pivot) right--;
        if(left>=right) break;
        swap(&a[left], &a[right]);
    }
    swap(&a[l], &a[right]);
    return right;
}

int solve(int* a, int n, int k){
    int l = 0, r = n-1;
    int t = n-k;
    while(1){
        int p = partition(a,l,r);
        if(p==t) return a[p];
        if(p<t) l = p+1;
        else r = p-1;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int k;
    scanf("%d", &k);
    printf("%d\n", solve(a,n,k));
    return 0;
}
