#include <stdio.h>
#include <limits.h>

void Problem1(int m, int n, int A[m][n], int ri, int ci, int rh, int ch)
{
    int B[m][n];
    int currSum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            currSum += A[i][j];
            B[i][j] = currSum;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    if (ri + rh - 1 >= m || ci + ch - 1 >= n)
    {
        printf("NOT POSSIBLE\n");
        return;
    }
    int ans = 0;
    for (int i = ri; i < ri + rh; i++)
    {
        for (int j = ci; j < ci + ch; j++)
        {
            ans += B[i][j];
        }
    }
    printf("%d\n", ans);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void Problem4(int n, int arr[])
{
    int firstPos = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && firstPos == INT_MAX)
            firstPos = i;
        if (arr[i] < 0 && i < firstPos)
            continue;
        if (arr[i] < 0 && i > firstPos)
        {
            int t = arr[firstPos];
            arr[firstPos] = arr[i];
            for (int j = i; j > firstPos; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[firstPos + 1] = t;
            i = firstPos;
            firstPos++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Problem3_BrutteForce(int n, int arr[], int i, int sum, int m, int idx[], int target, int* done){
    if(*done==1) return;
    if(sum>target) return;
    if(sum == target){
        *done=1;
        printf("POSSIBLE\n");
        for(int j = 0; j<m; j++){
            printf("%d ",idx[j]);
        }
        printf("\n");
        return;
    }
    if(i>=n) return;
    //not take
    Problem3_BrutteForce(n,arr,i+1,sum, m, idx, target, done);
    //take
    idx[m]=i;
    m++;
    Problem3_BrutteForce(n,arr,i+1,sum+arr[i], m, idx, target, done);
}

int main()
{
    // for problem 1
    // int m, n;
    // scanf("%d %d", &m, &n);
    // int A[m][n];
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         scanf("%d", &A[i][j]);
    //     }
    // }
    // int ri, ci, rh, ch;
    // scanf("%d %d %d %d", &ri, &ci, &rh, &ch);
    // Problem1(m, n, A, ri, ci, rh, ch);

    // for problem 3
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int tgt;
    scanf("%d", &tgt);
    int done = 0;
    int idx[10000];
    Problem3_BrutteForce(n,arr,0,0,0,idx,tgt,&done);
    if(done==0){
        printf("NOT POSSIBLE\n");
    }
    // for problem 4
    // int n;
    // scanf("%d", &n);
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    // Problem4(n, arr);
    return 0;
}