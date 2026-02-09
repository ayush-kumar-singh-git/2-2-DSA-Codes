#include <stdio.h>
#include <stdlib.h>

void bubble(int* a, int n){
    int swapped = 0;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(a[i+1]<a[i]){
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                swapped = 1;
            }
        }
    }while(swapped);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    bubble(a,n);
    int l=0, r=n-1;
    int found = 0;
    for(int i=0;i<n-2;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        l=i+1;
        r=n-1;
        while(l<r){
            int sum = a[i]+a[l]+a[r];
            if(sum==0){
                found = 1;
                printf("%d %d %d\n", a[i], a[l], a[r]);
                while(l<r && a[l]==a[l+1]) l++;
                while(l<r && a[r]==a[r-1]) r--;
                l++;
                r--;
            }else if(sum>0){
                r--;
            }else{
                l++;
            }
        }
    }
    if(!found){
        printf("NO TRIPLETS FOUND\n");
    }

    return 0;
}
