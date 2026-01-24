/*
 * Logic : Invariant : one side of mid is always sorted
 * TC O(log n)
 * SC O(1) other than the input list 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*)calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int tgt;
    scanf("%d", &tgt);
    int lo = 0, hi = n -1;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(a[mid]==tgt){
            ans = mid;
            break;
        }
        if(a[mid]<a[hi]){
            if(a[mid]<tgt && tgt<=a[hi]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }else{
            if(a[mid]>tgt && tgt>=a[lo]){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
    }
    printf("%d\n",ans);
    free(a);
    return 0;
}

