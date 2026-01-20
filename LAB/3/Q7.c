#include <stdio.h>
#include <stdlib.h>

void sort(int* a, int l, int r, int n){
    if(r>n-1) r=n-1;
    int swapped = 0;
    do{
        swapped = 0;
        for(int i=l;i<r;i++){
            if(a[i]>a[i+1]){
                int t = a[i];
                a[i] =a[i+1];
                a[i+1]=t;
                swapped = 1;
            }
        }
    }while(swapped==1);
}

void sol(int* a, int n){
    int curr = 1;
    int i = 0;
    while(i<n){
        sort(a,i,i+curr-1,n);
        i += curr;
        curr++;
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sol(a,n);
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
