/*
 * Logic : Just a bit modified bubble sort
 * TC O(n^2)
 * SC O(1) other than the input list 
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void bubble(int* a, int l, int r, int n){
    if(r>n) r=n;
    int len = r-l;
    int swapped = 0;
    for(int i=0;i<len-1;i++){
        swapped = 0;
        for(int j=l;j<r-i-1;j++){
            if(a[j+1]<a[j]){
                swap(&a[j+1], &a[j]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*) calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int curr = 1;
    int st = 0;
    while(st<n){
        bubble(a, st, st+curr, n);
        st+=curr;
        curr++;
    }
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}
