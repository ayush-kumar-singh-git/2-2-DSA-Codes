/*
 * Logic : make pair of val and index and then sort and check
 * TC O(n log n)
 * SC O(n) other than the input list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Pair_t{
    int val;
    int idx;
}pair;


int comp(pair p1, pair p2){
    if(p1.val != p2.val){
        return p1.val<p2.val;
    }
    return p1.idx<p2.idx;
}

void merge(pair a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    pair L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (comp(L[i],R[j]))
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];
}

void mergeSortHelper(pair a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortHelper(a, l, m);
        mergeSortHelper(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void mergeSort(pair* arr, int n){
    mergeSortHelper(arr, 0, n-1);
}


int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    pair* arr = malloc(n*sizeof(pair));
    for(int i=0;i<n;i++){
        int val;
        scanf("%d", &val);
        arr[i].val = val;
        arr[i].idx=i;
    }
    mergeSort(arr,n);
    int i =0 ;
    int found = 0;
    while(i<n){
        int j = i+1;;
        while(j<n && arr[j].val == arr[i].val){
            if(abs(arr[j].idx - arr[i].idx) > k){
                printf("%d %d\n", arr[i].idx,arr[j].idx);
                found = 1;
                break;
            }
            j++;
        }
        if(found) break;
        i = j;
    }
    if(!found){
        printf("-1\n");
    }
    free(arr);
    return 0;
}
