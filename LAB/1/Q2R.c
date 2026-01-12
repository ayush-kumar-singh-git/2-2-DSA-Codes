#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r1, c1;
    scanf("%d %d", &r1, &c1);
    int A[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1; j++){
            scanf("%d", &A[i][j]);
        }
    }
    int r2, c2;
    scanf("%d %d", &r2, &c2);
    int B[r2][c2];
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2; j++){
            scanf("%d", &B[i][j]);
        }
    }
    if(r2!=c1){
        printf("Not Possible\n");
        return 0;
    }
    int C[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int ans = 0;
            for(int k = 0; k<r2; k++){
                ans += (A[i][k]*B[k][j]);
            }
            C[i][j] = ans;
        }
    }

    for(int i=0;i<r1; i++){
        for(int j=0; j<c2; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
