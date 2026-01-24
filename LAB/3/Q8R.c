/*
 * Logic : Binary search on answer
 * TC O(n*log(INT_MAX)) = O(n) basically
 * SC O(1) other than the input list
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ok(int* a, int n, int d, int c){
    int cnt = 1;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(a[i]>c) return 0;
        if(a[i]+sum>c){
            cnt++;
            sum = a[i];
        }else{
            sum+=a[i];
        }
    }
    return cnt<=d;
}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int* a = (int*) calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int lo = 1, hi = INT_MAX;
    int ans = 0;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if(ok(a,n,d,mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    free(a);
    printf("%d\n", ans);
    return 0;
}
