#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ok(int* a, int n, int h, int x){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += (a[i]+x-1)/x;
    }
    return (cnt<=h);
}

int main()
{
    int n,h;
    scanf("%d %d", &n, &h);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int lo = 1, hi = INT_MAX;
    int ans = 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(ok(a,n,h,mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
