#include <stdio.h>
#include <stdlib.h>

int* mergeSortedLists(int* a, int m, int* b, int n){
    int* list = calloc(m+n, sizeof(int));
    int l=0, r=0, k=0;
    while(l<m &&  r<n){
        if(a[l]<=b[r]){
            list[k++]=a[l++];
        }else{
            list[k++]=b[r++];
        }
    }
    for(int i=l; i<m; i++){
        list[k++] = a[i];
    }
    for(int i=r; i<n; i++){
        list[k++] = b[i];
    }
    return list;
}

int* mergeSortHelp(int* a, int l, int r){
    if(l==r) return a;
    int m = l + (r-l)/2;
    int* left = mergeSortHelp(a,l,m);
    int* right = mergeSortHelp(a,m+1,r);
    return mergeSortedLists(left, m-l+1, right, r-m);
}

void mergeSort(int* a, int n){
    a = mergeSortHelp(a,0,n-1);
}

void printArr(int* a, int n){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a,n);
    printArr(a,n);
    return 0;
}
