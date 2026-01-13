#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* a, int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t = a[j];
                a[j]=a[j+1];
                a[j+1]=t;
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
    int a[n], b[n+2];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n+2;i++){
        scanf("%d", &b[i]);
    }
    bubbleSort(a,n);
    bubbleSort(b,n+2);
    int l=0, r=0;
    while(l<n && r<n+2){
        if(a[l]!=b[r]){
            printf("%d ", b[r++]);
        }
        if(a[l]==b[r]){
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
