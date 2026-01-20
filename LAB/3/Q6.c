#include <stdio.h>
#include <stdlib.h>

int f(int x){
    int val =2*x*x*x;
    val -= (x*x);
    val += (5*x);
    return val;
}

int main()
{
    int y;
    scanf("%d", &y);
    int lo = 0, hi=40;
    int ans =0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(f(mid)<=y){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
