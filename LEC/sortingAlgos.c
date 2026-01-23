#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Sorting Algorithm    TC(Worst)     TC(Best)          SC      Stable
 * Bubble Sort          O(n^2)        O(n)              O(1)    YES  
 * Insertion Sort       O(n^2)        O(n)              O(1)    YES
 * Merge Sort           O(nlogn)      O(nlogn)          O(n)    YES
 * Quick Sort           O(n^2)        O(nlogn)          O(1)    NO
 * Count Sort           O(n)          O(n)              O(n)    YES
 */

void bubbleSort(int* a, int n);
void insertionSort(int* a, int n);
void mergeSort(int* a, int n);
void mergeSortHelp(int* a, int l, int r);
void merge(int* a, int l, int m, int r);
void quickSort(int* a, int n);
int partition(int* a, int l, int r);
void quickSortHelp(int* a, int l, int r);
void print(int* a, int n);
void swap(int* a, int* b);
void countSort(int* a, int n);
int max(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*) calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    countSort(a,n);
    print(a,n);
    free(a);
    return 0;
}

void bubbleSort(int* a, int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0; j<n-i-1; j++){
            if(a[j+1]<a[j]){
                swap(&a[j], &a[j+1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
    return;
}

void insertionSort(int* a, int n){
    int i = 1;
    while(i<n){
        int j = i-1;
        int val = a[i];
        while(j>=0 && a[j]>val){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
        i++;
    }
    return;
}

void mergeSort(int* a, int n){
    mergeSortHelp(a,0,n-1);
    return;
}

void mergeSortHelp(int* a, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSortHelp(a,l,m);
        mergeSortHelp(a,m+1,r);
        merge(a,l,m,r);
    }
    return;
}
void merge(int* a, int l, int m, int r){
    int lLen = m-l+1, rLen = r-m;
    int* L = (int*) calloc(lLen, sizeof(int));
    int* R = (int*) calloc(rLen, sizeof(int));
    for(int i=l;i<=r;i++){
        if(i<=m){
            L[i-l] = a[i];
        }else{
            R[i-m-1] = a[i]; 
        }
    }
    int i = 0, j = 0, k = l;
    while(i<lLen && j<rLen){
        if(L[i]<=R[j]){
            a[k++] = L[i++];
        }else{
            a[k++] = R[j++];
        }
    }
    while(i<lLen){
        a[k++] = L[i++];
    }
    while(j<rLen){
        a[k++] = R[j++];
    }
    free(L);
    free(R);
}

void quickSort(int* a, int n){
    quickSortHelp(a,0,n-1);
    return;
}

int partition(int* a, int l, int r) {
    int pivot = a[l];
    int i = l + 1;
    int j = r;

    while (1) {
        while (i <= r && a[i] <= pivot) i++;
        while (j >= l && a[j] > pivot) j--;
        if (i >= j) break;
        swap(&a[i], &a[j]);
    }

    swap(&a[l], &a[j]);
    return j;
}

void quickSortHelp(int* a, int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSortHelp(a, l, p - 1);
        quickSortHelp(a, p + 1, r);
    }
}

void countSort(int* a, int n){
    int maxm = INT_MIN;
    for(int i=0;i<n;i++){
        maxm = max(maxm, a[i]);
    }
    int* aux = (int*)calloc(maxm+1, sizeof(int));
    for(int i=0;i<n;i++){
        aux[a[i]]++;
    }

    int* ps = (int*)calloc(maxm+1, sizeof(int));
    ps[0] = aux[0];
    for(int i=1;i<=maxm;i++){
        ps[i] = (ps[i-1]+aux[i]);
    }
    int* new = (int*) calloc(n, sizeof(int));
    for(int i=n-1;i>=0;i--){
        if(aux[a[i]]==0) continue;
        else {
            new[ps[a[i]]-1] = a[i];
            ps[a[i]]--;
        }
    }
    for(int i=0;i<n;i++){
        a[i]=new[i];
    }
    free(aux);
    free(new);
    free(ps);
    return;
}

void print(int* a, int n){
    for(int i=0;i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

int max(int a, int b){
    return a>b?a:b;
}
