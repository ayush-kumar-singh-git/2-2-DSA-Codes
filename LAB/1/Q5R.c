#include <stdio.h>
#include <stdlib.h>

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
    int C[n1+n2];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(A[i]<=B[j]){
            C[k]=A[i];
            i++;
        }else{
            C[k]=B[j];
            j++;
        }
        k++;
    }
    for(int x=i;x<n1;x++){
        C[k]=A[x];
        k++;
    }
    for(int x = j; x<n2; x++){
        C[k]=B[x];
        k++;
    }
    for(int i=0;i<n1+n2;i++){
        printf("%d ", C[i]);
    }
    printf("\n");
    return 0;
}
