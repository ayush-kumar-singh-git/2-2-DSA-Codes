#include <stdio.h>
#include <stdlib.h>

#define INF 2147483647

int lowerEl(int* a, int n, int x){
    int lo =0 , hi = n-1;
    int ans = n;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(a[mid]>=x){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return ans;
}

int min(int a, int b){
    return a<b?a:b;
}

int main()
{
    int m;
    scanf("%d", &m);
    int a[m];
    for(int i=0;i<m;i++) scanf("%d", &a[i]);
    int n;
    scanf("%d", &n);
    int b[n];
    for(int i=0;i<n;i++) scanf("%d", &b[i]);
    int goal = (n+m-1)/2;
    int lo = 0, hi = m-1;
    int ans = -1;
    int fromA = 0, fromB = 0;
    int found = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int curr = lowerEl(b,n,a[mid]);
        if(curr + mid == goal){
            found = 1;
            ans = a[mid];
            fromA = mid;
            fromB = curr-1;
            break;
        }else if(curr+mid < goal){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    if(!found){
        lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int curr = lowerEl(a,m,b[mid]);
            if(curr + mid == goal){
                found = 1;
                ans = b[mid];
                fromB = mid;
                fromA = curr-1;
                break;
            }else if(curr+mid < goal){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
    }
    if((n+m)%2==1){
        printf("%d\n", ans);
    }else{
        int nextA = (fromA + 1 < m) ? a[fromA + 1] : INF;
        int nextB = (fromB + 1 < n) ? b[fromB + 1] : INF;
        double avg = ans + min(nextA, nextB);
        printf("%lf\n", avg / 2);
    }
    return 0;
}
