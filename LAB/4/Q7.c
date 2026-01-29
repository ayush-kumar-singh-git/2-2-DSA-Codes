/*
 * Logic : Just Brutte force and use BS for checking if it is missing or not
 * TC O(n log n) types (not exactly)
 * SC O(1) other than the input list
 */
#include <stdio.h>
#include <stdlib.h>


int present(int* a, int n, int x){
    int lo = 0, hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]==x) return 1;
        if(a[mid]>x){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return 0;
}
int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int curr = 1;
    int cnt =0 ;
    while(1){
        if(present(a,n,curr)){
            curr++;
        }else{
            cnt++;
            if(cnt==k){
                printf("%d\n", curr);
                break;
            }
            curr++;
        }
    }
    return 0;
}
