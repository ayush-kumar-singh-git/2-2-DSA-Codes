#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int x;
    scanf("%d", &x);
    int lo = 0, hi = n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]>=x){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    lo = 0, hi = n-1;
    int ans1=-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]<=x){
            ans1 = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
     if(ans == -1||ans1==-1||ans>ans1){
        printf("-1 -1\n");
        return 0;
    }
    printf("%d %d\n", ans , ans1);
    return 0;
}
