#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble(int* arr, int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(&arr[j], &arr[j+1]);
                swapped=1;
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
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", & arr[i]);
    bubble(arr,n);
    int i=0;
    while(i<n){
        int j=i+1;
        while(j<n && arr[j]==arr[i]) j++;
        printf("%d -> %d\n", arr[i], j-i);
        i=j;
    }
    return 0;
}
