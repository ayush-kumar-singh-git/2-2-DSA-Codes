#include <stdio.h>
#include <stdlib.h>

int isSorted(int* arr, int n, int i){
    if(i==n-1) return 1;
    if(arr[i]<arr[i+1]) return 0;
    return isSorted(arr,n,i+1);
}

void bitStrings(int n, int i){
    if(i==(1<<n)){
        return;
    }
    bitStrings(n, i+1);
    int cnt = 0;
    while(i>0){
        cnt++;
        printf("%d", i%2);
        i/=2;
    }
    for(int j=cnt;j<n;j++) printf("0");
    printf("\n");
}

// different methods for swapping a and b

void swapUsingThirdVar(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void swapUsingXor(int* a, int* b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void swapUsingPM(int* a, int* b){
    *a = *a + *b;
    *b = * a - *b;
    *a = *a - *b;
}

int main()
{
   int n;
   scanf("%d", &n);
   //bitStrings(n, 0);
   int arr[n];
   for(int i=0;i<n;i++) scanf("%d", &arr[i]);
   printf("%d\n", isSorted(arr,n,0));
    return 0;
}
