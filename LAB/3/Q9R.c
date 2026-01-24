/*
 * Logic : Use merge step of merge sort to count inversions
 * TC O(n log n)
 * SC O(n) other than the input list
 */

#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int l, int m, int r, int* ans){
    int lsz = m-l+1, rsz = r-m;
    int* left = (int*) calloc(lsz, sizeof(int));
    int* right = (int*) calloc(rsz, sizeof(int));
    for(int i=l;i<=r;i++){
        if(i<=m){
            left[i-l] = a[i];
        }else{
            right[i-m-1] = a[i];
        }
    }
    int i=0,j=0,k=l;
    while(i<lsz && j<rsz){
        if(left[i]<=right[j]){
            a[k++] = left[i++];
        }else{
            *ans += (lsz-i);
            a[k++] = right[j++];
        }
    }
    while(i<lsz){
        a[k++] = left[i++];
    }
    while(j<rsz){
        a[k++] = right[j++];
    }
    free(left);
    free(right);
    return;
}

void mergeSort(int* a, int l, int r, int* ans){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(a,l,m,ans);
        mergeSort(a,m+1,r,ans);
        merge(a,l,m,r,ans);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*) calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int ans = 0;
    mergeSort(a,0,n-1,&ans);
    free(a);
    printf("%d\n", ans);
    return 0;
}
