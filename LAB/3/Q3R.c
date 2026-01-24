/*
 * Logic : Binary search on answer
 * TC O(n*log(INT_MAX)) = O(n) basically
 * SC O(1) other than the input list
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int valid(int* a, int n, int s, int h){
    int count = 0;
    for(int i=0;i<n;i++){
        count += (a[i]+s-1)/s;
    }
    return count<=h;
}

int solve(int* a, int n, int h){
    int lo = 1, hi = INT_MAX;
    int ans = 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(valid(a,n,mid,h)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n,h;
    scanf("%d %d", &n, &h);
    int* a = (int*)calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int ans = solve(a,n,h);
    printf("%d\n", ans);
    free(a);
    return 0;
}
