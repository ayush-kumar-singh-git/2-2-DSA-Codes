#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* a, int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t = a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
    return;
}

int upperBound(int* arr, int l, int r, int tgt){
    int ans = r+1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]>tgt){
            ans = m;
            r = m- 1;
        }else{
            l = m+1;
        }
    }
    return ans;
}

int max(int a, int b){
    return a>b?a:b;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    bubbleSort(a,n);
    int ans = 0;
    for(int i=0;i<n;i++){
        int j = upperBound(a, i, n-1, a[i]+k);
        ans = max(ans, j-i);
    }
    printf("%d\n", ans);
    return 0;
}
