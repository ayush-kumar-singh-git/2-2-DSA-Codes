#include <stdio.h>
#include <stdlib.h>

int ok(int* a, int n, int k, int m){
    int last = a[0];
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(a[i]-last >= m){
            last = a[i];
            cnt++;
        }
    }
    return cnt >= k;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int lo = 0, hi = a[n-1]-a[0];
    int ans  = 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(ok(a,n,k,mid)){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
