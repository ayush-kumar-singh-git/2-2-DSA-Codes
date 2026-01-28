/*
 * Logic :Pure Binary Search
 * TC O(log (INT_MAX))
 * SC O(1)
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int K;
    scanf("%d", &K);
    long long lo = 1, hi = INT_MAX;
    long long ans = -1;
    while(lo<=hi){
        long long mid = lo + (hi-lo)/2;
        if(mid*mid<=K){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    printf("%d\n",(int)ans);
    return 0;
}
