#include <stdio.h>
#include <stdlib.h>

void swap(int* a , int* b){
    *a = *a + *b;
    *b = *a-*b;
    *a = *a-*b;
    return;
}

void bubbleSort(int* arr, int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped =1;
            }
        }
        if(!swapped) break;
    }
}
int main()
{
    int n1;
    scanf("%d", &n1);
    int A[n1];
    for(int i=0; i<n1; i++){
        scanf("%d", &A[i]);
    }
    int n2;
    scanf("%d", &n2);
    int B[n2];
    for(int i=0; i<n2; i++){
        scanf("%d", &B[i]);
    }
    int C[n1+n2];
    for(int i=0;i<n1+n2;i++){
        if(i>=n1){
            C[i] = B[i-n1];
        }else{
            C[i]=A[i];
        }
    }
    bubbleSort(C, n1+n2); // merge sorted lists noob 
    bubbleSort(A, n1);
    bubbleSort(B, n2);
    printf("Union: ");
    int i=0;
    while(i<n1+n2){
        int j= i+1;
        while(j<n1+n2 && C[j]==C[i]) j++;
        printf("%d ", C[i]);
        i=j;
    }
    printf("\nIntersection: ");
    int l =0, r=0;
    while(l<n1 && r<n2){
        if(A[l]==B[r]){
            if(l>0 && r>0){
                if(A[l-1]==A[l]){
                    l++;
                    r++;
                    continue;
                }
            }
            printf("%d ", A[l]);
            l++;
            r++;
        }
        else if(A[l]>B[r]) r++;
        else l++;
    }
    printf("\n");
    return 0;
}
