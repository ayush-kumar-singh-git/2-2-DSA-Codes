#include <stdio.h>
#include <stdlib.h>

void bubble(int* arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n+2];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n+2;i++) scanf("%d", &b[i]);
    bubble(a,n);
    bubble(b,n+2);
    int l=0, r=0;
    while(l<n && r<n+2){
        if(a[l]!=b[r]){
            printf("%d ", b[r]);
            r++;
        }else{
            l++;
            r++;
        }
    }
    while(r<n+2){
        printf("%d ", b[r++]);
    }
    printf("\n");
    return 0;
}
