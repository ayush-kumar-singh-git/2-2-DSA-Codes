#include <stdio.h>
#include <stdlib.h>

void rotateClock(int m, int n, int a[m][n], int srow, int erow, int scol, int ecol){
    int prev = a[srow][scol];
    for(int i=scol+1;i<=ecol;i++){
        int temp = a[srow][i];
        a[srow][i] = prev;
        prev = temp;
    }
    for(int i=srow+1;i<=erow;i++){
        int temp = a[i][ecol];
        a[i][ecol] = prev;
        prev = temp;
    }
    for(int i = ecol-1; i>=scol; i--){
        int temp = a[erow][i];
        a[erow][i] = prev;
        prev = temp;
    }
    for(int i=erow-1;i>=srow;i--){
        int temp = a[i][scol];
        a[i][scol] = prev;
        prev = temp;
    }
    return;
}

void rotateAntiClock(int m, int n, int a[m][n], int srow, int erow, int scol, int ecol){
    int prev = a[srow][scol];
    for(int i=srow+1;i<=erow;i++){
        int temp = a[i][scol];
        a[i][scol] = prev;
        prev = temp;
    }
    for(int i=scol+1;i<=ecol;i++){
        int temp = a[erow][i];
        a[erow][i] = prev;
        prev = temp;
    }
    for(int i = erow-1;i>=srow;i--){
        int temp = a[i][ecol];
        a[i][ecol] = prev;
        prev = temp;
    }
    for(int i=ecol-1; i>=scol; i--){
        int temp = a[srow][i];
        a[srow][i] = prev;
        prev = temp;
    }
    return;
}

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
    int srow = 0, scol = 0, erow=m-1, ecol = n-1;
    int cnt = 0;
    while(srow<erow && scol<ecol){
        cnt++;
        if(cnt%2)
            rotateClock(m,n,a,srow,erow,scol,ecol);
        else
            rotateAntiClock(m,n,a,srow,erow,scol,ecol);
        srow++;
        erow--;
        scol++;
        ecol--;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
