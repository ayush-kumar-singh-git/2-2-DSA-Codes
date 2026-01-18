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

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    bubble(a,n);
    int eve=0, odd=0;
    for(int i=0;i<n;i++){
        if(i%2==0 && a[i]%2==0) eve++;
        if(i%2==1 && a[i]%2==1) odd++;
    }
    printf("%d,%d\n", eve,odd);
    return 0;
}
