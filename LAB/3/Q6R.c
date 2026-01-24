/*
 * Logic : Classic monotonic function BS
 * TC O(1)
 * SC O(1) other than the input list
 */

#include <stdio.h>
#include <stdlib.h>

int f(int x){
    int val = (2*x*x*x)-(x*x)+(5*x);
    return val;
}

int main()
{
    int Y;
    scanf("%d", &Y);
    int lo = 0, hi = 80;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(f(mid)<=Y){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
