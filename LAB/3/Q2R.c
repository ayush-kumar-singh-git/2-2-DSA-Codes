/*
 * Logic : check if boundaries are peak, else check the remaining using BS
 * TC O(log n)
 * SC O(1) other than the input list
 * */

#include <stdio.h>
#include <stdlib.h>

int solve(int* a, int n){
    // check if boundaries are peak
    if(a[n-1]>a[n-2]) return n-1;
    if(a[0]>a[1]) return 0;
    //check all other elements using bin search
    int lo =1, hi = n-2;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid-1]<a[mid] && a[mid]>a[mid+1]) return mid;
        if(a[mid]<a[mid+1]){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*)calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int ans = solve(a,n);
    printf("%d\n", ans);
    free(a);
    return 0;
}
