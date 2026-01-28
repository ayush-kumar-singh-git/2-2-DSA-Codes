/*
 * Logic : Staircase Search
 * TC O(m+n)
 * SC O(1) other than the input
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int tgt;
    scanf("%d", &tgt);
    int i=0, j=n-1;
    while(i<m && j>=0){
        if(a[i][j]==tgt){
            printf("%d %d\n",i,j);
            return 0;
        }else if(a[i][j]<tgt){
            i++;
        }else{
            j--;
        }
    }
    printf("-1\n");
    return 0;
}
