#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1;
    scanf("%d", &n1);
    int arr1[n1];
    for(int i=0;i<n1;i++) scanf("%d", &arr1[i]);
    int n2;
    scanf("%d", &n2);
    int arr2[n2];
    for(int i=0;i<n2;i++) scanf("%d", &arr2[i]);
    int arr[n1+n2];
    int l=0, r=0, k=0;
    while(l<n1 && r<n2){
        if(arr1[l]<= arr2[r]){
            arr[k]=arr1[l];
            l++;
        }else{
            arr[k]=arr2[r];
            r++;
        }
        k++;
    }
    for(int i=l;i<n1;i++){
        arr[k]=arr1[i];
        k++;
    }
    for(int i=r;i<n2;i++){
        arr[k]=arr2[i];
        k++;
    }
    for(int i=0;i<n1+n2;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
