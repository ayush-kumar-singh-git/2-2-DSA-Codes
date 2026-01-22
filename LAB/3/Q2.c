#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int lo = 1, hi = n-2;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(a[mid]> a[mid-1] && a[mid] > a[mid+1]){
            printf("%d\n", mid);
            break;
        }
        else if(a[mid+1]>a[mid]){
            hi = mid + 1;
        }else{
            lo = mid - 1;
        }
    }
    return 0;
}
