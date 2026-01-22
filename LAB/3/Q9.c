#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int l, int m, int r, int* ans){
    int L[m-l+1], R[r-m];
    for(int i=l;i<=m;i++){
        L[i-l] = a[i];
    }
    for(int i=m+1;i<=r;i++){
        R[i-m-1] = a[i];
    }
    int i=0, j=0, k = l;
    while(i<m-l+1 && j<r-m){
        if(L[i]<=R[j]){
            a[k++]=L[i++];
        }else{
            *ans += (m - l + 1 - i);
            a[k++]=R[j++];
        }
    }
    while(i<m-l+1){
        a[k++]=L[i++];
    }
    while(j<r-m){
        a[k++]=R[j++];
    }
}

void mergeSort(int* a, int l, int r, int* ans){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a,l,m, ans);
        mergeSort(a,m+1,r, ans);
        merge(a,l,m,r, ans);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int ans = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0,n-1, &ans);
    printf("%d\n", ans);
    /*
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    */
    return 0;
}
