#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int left = 0, right = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        right ^= a[i];
    }
    left = a[0];
    for(int i=1;i<n-1;i++){
        right = (right^left)^a[i];
        if(left == right){
            printf("%d ", i+1);
        }
        right = (right^left)^a[i];
        left ^= a[i];
    }
    printf("\n");
    return 0;
}
