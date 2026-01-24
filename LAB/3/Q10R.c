/*
 * Logic : Here We Go :
 *             1. First take input and select the smaller array(a) for bs
 *             2. total is the total number of elements
 *             3. leftSize is the # of elements to be at the left of M(inc)
 *             4. Note leftSize = (total+1)/2 always
 *             5. check on 1 2 3 4 5, 1 2 3 4 5 6.
 *             6. Now bs for i, note we must take j=leftSize-i from b
 *             7. a[i] <= b[j + 1] && b[j] <= a[i + 1]) is the perfect match
 *             8. if it is a perfect match based on parity of tot print ans
 *             9. else if a[i] > b[j + 1] we took too much from a
 *             10. go lower hi = i - 1
 *             11. else we took too less from a
 *             12 go higher lo = i + 1
 * TC O(log(min(m,n)))
 * SC O(1) other than the input list
 */

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
                float sum  = max(a[i],b[j]);
                sum += min(a[i+1], b[j+1]);
                printf("%f\n", sum/2.0);
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
