#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void bubble(int* a, int*d, int n){
    int swapped = 0;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(d[i+1]!=d[i] && d[i+1]<d[i]){
                swap(&a[i], &a[i+1]);
                swap(&d[i], &d[i+1]);
                swapped = 1;
                continue;
            }else if(d[i+1]==d[i] && a[i+1]>a[i]){
                swap(&a[i], &a[i+1]);
                swap(&d[i], &d[i+1]);
                swapped = 1;
                continue;
            }
        }
    }while(swapped);
}

int divisor(int n){
    int count = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            int j = n/i;
            if(i!=j) count++;
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int d[n];
    for(int i=0;i<n;i++){
        d[i] = divisor(a[i]);
    }
    bubble(a,d,n);
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
