#include <stdio.h>
#include <stdlib.h>

void bubble(int* arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    return;
}

int max(int a, int b){
    return a>b?a:b;
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    bubble(a,n);
    int ans = 0;
    for(int i=0;i<n;i++){
        int fnd = 0;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]+k){
                ans = max(ans, j-i);
                fnd = 1;
                break;
            }
        }
        if(!fnd){
            ans = max(ans, n-i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
