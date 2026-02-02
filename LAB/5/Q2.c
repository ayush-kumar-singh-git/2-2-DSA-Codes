#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int i = 0;
    int maxLen = 0;
    int l=-1,  r=-1;
    while(i<n-1){
        int j = i+1;
        int init = a[j] - a[i];
        while(j<n && a[j]-a[j-1]==init) j++;
        if(j-i>maxLen){
            maxLen = j-i;
            l = i;
            r = j-1;
        }
        i = j-1;
    }
    printf("%d %d\n", l+1, r+1);
    return 0;
}
