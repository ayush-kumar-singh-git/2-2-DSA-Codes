/*
 * Logic : BS on the range [min,max] for #elements<=mid
 * TC O(m log n log (max-min))
 * SC O(1) other than the input list
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b){ return a<b?a:b; }
int max(int a, int b){ return a>b?a:b; }

int main()
{
    int m, n;
    scanf("%d %d", &m,&n);
    int a[m][n];
    int lo  = INT_MAX, hi = INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
            if(j==0) lo = min(lo, a[i][j]);
            if(j==n-1) hi = max(hi, a[i][j]);
        }
    }
    int leftHalf = (m*n+1)/2;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int cnt = 0;

        for(int i=0;i<m;i++){
            int l = 0, r = n-1;
            int x = 0;
            while(l<=r){
                int middle = l+(r-l)/2;
                if(a[i][middle]<=mid){
                    x = middle+1;
                    l = middle + 1;
                }else{
                    r = middle - 1;
                }
            }
            cnt += x;
        }
        if(cnt < leftHalf){
            lo = mid + 1;
        }else{
            ans = mid;
            hi = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
