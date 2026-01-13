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
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    bubbleSort(a,n);
    int e=0, o=0;
    for(int i=0;i<n;i++){
        if(i%2==0 && a[i]%2==0){
            e++;
        }
        if(i%2==1 && a[i]%2==1){
            o++;
        }
    }
    printf("%d,%d\n", e,o);
    return 0;
}
