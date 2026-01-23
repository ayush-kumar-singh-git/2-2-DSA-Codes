#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int max(int a, int b){ return a>b? a:b; }

int min(int a, int b){ return a<b? a:b; }

void swapInt(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void swapArr(int** a, int** b){
    int* t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int m;
    scanf("%d", &m);
    int* a = (int*) calloc(m+2, sizeof(int));
    a[0] = INT_MIN, a[m+1]=INT_MAX;
    for(int i=1;i<=m;i++) scanf("%d", &a[i]);

    int n;
    scanf("%d", &n);
    int* b = (int*) calloc(n+2, sizeof(int));
    b[0] = INT_MIN, b[n+1]=INT_MAX;
    for(int i=1;i<=n;i++) scanf("%d", &b[i]);
    
    if(m>n){
        swapInt(&m, &n);
        swapArr(&a, &b);
    }

    int total = m + n;
    int leftSize = (total + 1) / 2;
    int lo = 0, hi = m;

    while (lo <= hi) {
        int i = lo + (hi-lo)/2;
        int j = leftSize - i;
        if (a[i] <= b[j + 1] && b[j] <= a[i + 1]) {
            if (total % 2 == 1) {
                printf("%d\n", max(a[i], b[j]));
            } else {
                double median = (max(a[i], b[j]) + min(a[i + 1], b[j + 1])) / 2.0;
                printf("%lf\n", median);
            }
            break;
        }
        else if (a[i] > b[j + 1]) {
            hi = i - 1;
        }
        else {
            lo = i + 1;
        }
    }
    free(a);
    free(b);
    return 0;
}
