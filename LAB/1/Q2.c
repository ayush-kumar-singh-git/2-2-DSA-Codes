#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r1,c1;
    scanf("%d %d", &r1, &c1);
    int A[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d", &A[i][j]);
        }
    }

    int r2,c2;
    scanf("%d %d", &r2, &c2);
    int B[r2][c2];
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d", &B[i][j]);
        }
    }

    if(c1!=r2){
        printf("Not Possible");
        return 0;
    }

    int M[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int tot = 0;
            for(int k=0; k<r2; k++){
                tot+=A[i][k]*B[k][j];
            }
            M[i][j]=tot;
        }
    }

    for(int i=0;i<r1;i++){
        for(int j=0; j<c2; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}
