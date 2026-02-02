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
    int a1,b1,a2,b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
    a1--, b1--, a2--, b2--;
    int ps[m][n];
    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) ps[0][0] = a[0][0];
            else if(i==0) ps[i][j] = ps[i][j-1] + a[i][j];
            else if(j==0) ps[i][j] = ps[i-1][j] + a[i][j];
            else 
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", ps[i][j]);
        }
        printf("\n");
    }
    int ans = ps[a2][b2];
    if(a1 > 0) ans -= ps[a1-1][b2];
    if(b1 > 0) ans -= ps[a2][b1-1];
    if(a1 > 0 && b1 > 0) ans += ps[a1-1][b1-1];
    printf("Sum = %d\n", ans);
    return 0;
}
