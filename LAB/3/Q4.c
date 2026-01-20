#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int tgt;
    scanf("%d",  &tgt);
    int lo = 0, hi = n-1;
    int found = 0;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(a[mid]==tgt){
            found = 1;
            printf("%d\n", mid);
            break;
        }
        if(a[mid]<a[n-1]){
            if(a[mid]< tgt && tgt <= a[hi]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }else{
            if(a[lo]<= tgt && tgt < a[mid]){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
    }
    if(!found){
        printf("-1\n");
    }
    return 0;
}
