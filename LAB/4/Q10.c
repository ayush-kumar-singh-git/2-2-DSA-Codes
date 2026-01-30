/*
 * Logic : Classic binary search on ans
 * TC O(n log (MaxOfArr))
 * SC O(1) other than the input list
 * Better to use long long to avoid overflow but can manage with int
 */

#include <stdio.h>
#include <stdlib.h>

int ok(int* a, int n, int g, int x){
    int tot = 0;
    for(int i=0;i<n;i++){
        if(a[i]<x) tot+=a[i];
        else tot+=x;
    }
    return g<=tot;
}

int maxm(int* a, int n){
    int ans = a[0];
    for(int i=0;i<n;i++){
        if(a[i]>ans) ans = a[i];
    }
    return ans;
}

int main()
{
    int n,g;
    scanf("%d %d", &n, &g);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int lo = 1, hi = maxm(a,n);
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(ok(a,n,g,mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
