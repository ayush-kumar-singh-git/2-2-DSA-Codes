#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n+2], au[n], bu[n+2];
    for(int i =0; i<n; i++){
        scanf("%d", &a[i]);
        au[i]=0;
    }
    for(int i =0; i<n+2; i++){
        scanf("%d", &b[i]);
        bu[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n+2;j++){
            if(a[i]==b[j]){
                if(au[i]==0 && bu[j]==0){
                    au[i]=1;
                    bu[j]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n+2;i++){
        if(bu[i]==0){
            printf("%d ", b[i]);
        }
    }
    printf("\n");
    return 0;
}
