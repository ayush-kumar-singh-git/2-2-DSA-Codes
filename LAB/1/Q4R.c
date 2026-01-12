#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
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

void findUnion(int* A, int n1, int* B, int n2){
    int C[n1+n2];
    for(int i=0;i<n1+n2;i++){
        if(i<n1){
            C[i] = A[i];
        }else{
            C[i] = B[i-n1];
        }
    }
    bubble(C, n1+n2);
    printf("Union: ");
    int i =0;
    while(i<n1+n2){
        int j = i+1;
        while(C[j]==C[i]) j++;
        printf("%d ", C[i]);
        i=j;
    }
    printf("\n");
}

void findIntersection(int* A, int n1, int* B, int n2){
    int i=0, j=0;
    printf("Intersection: ");
    while(i<n1 && j<n2){
        if(A[i]==B[j]){
            printf("%d ",A[i]);
            int curr = A[i];
            while(i<n1 && A[i]==curr) i++;
            while(j<n2 && B[j]==curr) j++;
        }else if(A[i]<B[j]) i++;
        else j++;
    }
    printf("\n");
}

int main()
{
    int n1;
    scanf("%d", &n1);
    int A[n1];
    for(int i=0;i<n1;i++){
        scanf("%d", &A[i]);
    }
    int n2;
    scanf("%d", &n2);
    int B[n2];
    for(int i=0;i<n2;i++){
        scanf("%d", &B[i]);
    }
    bubble(A,n1);
    bubble(B, n2);
    findUnion(A, n1, B, n2);
    findIntersection(A, n1, B, n2);
    return 0;
}
