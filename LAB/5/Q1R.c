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
    int r1,c1,r2,c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    int ps[m+1][n+1];
    for(int i=0;i<=m;i++) ps[i][0]=0;
    for(int j=0;j<=n;j++) ps[0][j]=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ps[i+1][j+1] = ps[i][j+1]+ps[i+1][j]-ps[i][j]+a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ", ps[i][j]);
        }
        printf("\n");
    }
    int sum = ps[r2][c2] - ps[r1-1][c2] - ps[r2][c1-1] + ps[r1-1][c1-1];
    printf("Sum = %d\n",sum);
    return 0;
}
