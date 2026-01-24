/*
 * Logic : Pure Binary Search, twice
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
    int fOcc = -1, lOcc = -1;
    int lo = 0, hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(a[mid]>=tgt){
            if(a[mid]==tgt)
                fOcc = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    lo = 0, hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]<=tgt){
            if(a[mid]==tgt)
                lOcc = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    if(fOcc!=-1 && lOcc!=-1 && fOcc<=lOcc){
        printf("%d %d\n", fOcc, lOcc);
    }else{
        printf("-1 -1\n");
    }
    free(a);
    return 0;
}


