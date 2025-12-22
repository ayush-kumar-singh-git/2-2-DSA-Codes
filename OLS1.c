#include <stdio.h>
#include <stdbool.h>

void problem1();
void problem2(); // can imporve implementation but lite
bool checkSubMat(int m, int n, int A[m][n], int p, int q, int B[p][q]);
bool checkRow(int m, int n, int A[m][n], int p, int q, int B[p][q]);
bool checkCol(int m, int n, int A[m][n], int p, int q, int B[p][q]);
int main()
{
    problem2();
    return 0;
}

void problem1()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int A[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    int B[m][n];
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += A[i][j];
            B[i][j] = sum;
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
    int ri, ci, rh, ch;
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);
    if (ri + rh - 1 >= m || ci + ch - 1 >= n)
    {
        printf("NOT POSSIBLE\n");
    }
    else
    {
        long long ans = 0;
        for (int i = ri; i <= ri + rh - 1; i++)
        {
            for (int j = ci; j <= ci + ch - 1; j++)
            {
                ans += B[i][j];
            }
        }
        printf("%lld\n", ans);
    }
}

void problem2()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int A[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    int p, q;
    scanf("%d %d", &p, &q);
    int B[p][q];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    if (checkSubMat(m, n, A, p, q, B))
    {
        printf("YES\n");
    }
    else if (!checkRow(m, n, A, p, q, B) && !checkCol(m, n, A, p, q, B))
    {
        printf("NO\n");
    }
    else
    {
        printf("PARTIAL\n");
    }
}

bool checkSubMat(int m, int n, int A[m][n], int p, int q, int B[p][q])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool ok = true;
            if (i + p - 1 < m && j + q - 1 < n)
            {
                for (int a = i; a <= i + p - 1; a++)
                {
                    for (int b = j; b <= j + q - 1; b++)
                    {
                        if (A[a][b] != B[a - i][b - j])
                        {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                continue;
            }
            if (ok)
                return true;
        }
    }
    return false;
}

bool checkRow(int m, int n, int A[m][n], int p, int q, int B[p][q])
{
    for (int rb = 0; rb < p; rb++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool ok = true;
                if (j + q - 1 >= n)
                    continue;
                else
                {
                    for (int a = j; a <= j + q - 1; a++)
                    {
                        if (B[rb][a - j] != A[i][a])
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok)
                    return true;
            }
        }
    }
    return false;
}

bool checkCol(int m, int n, int A[m][n], int p, int q, int B[p][q])
{
    for (int cb = 0; cb < q; cb++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool ok = true;
                if (i + p - 1 >= m)
                    continue;
                else
                {
                    for (int a = i; a <= i + p - 1; a++)
                    {
                        if (B[a - i][cb] != A[a][j])
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok)
                    return true;
            }
        }
    }
    return false;
}