#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void problem1();
void problem2(); // can imporve implementation but lite
bool checkSubMat(int m, int n, int A[m][n], int p, int q, int B[p][q]);
bool checkRow(int m, int n, int A[m][n], int p, int q, int B[p][q]);
bool checkCol(int m, int n, int A[m][n], int p, int q, int B[p][q]);
void problem3();
void foo1(int *arr, int n, int target, int i, int *idxs, int k, int sum, bool *done); // can reduce 1 parameter
void problem4();
void problem5(); // did not implement connectors logic
void problem6();
bool isPrime(int n);
void problem7();
bool hasStrChars(char *line, int st, int end, int *tgt);
void problem8();
bool isPalindrome(char *word, int len);

int main()
{
    problem8();
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

void problem3()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int tgt;
    scanf("%d", &tgt);
    int idxs[n];
    bool done = false;
    foo1(arr, n, tgt, 0, idxs, 0, 0, &done);
    if (!done)
    {
        printf("NOT POSSIBLE\n");
    }
}

void foo1(int *arr, int n, int target, int i, int *idxs, int k, int sum, bool *done)
{
    if (sum == target)
    {
        printf("POSSIBLE\n");
        for (int x = 0; x < k; x++)
        {
            printf("%d ", idxs[x]);
        }
        printf("\n");
        *done = true;
        return;
    }
    if (*done || i >= n || sum > target)
    {
        return;
    }
    // not take
    foo1(arr, n, target, i + 1, idxs, k, sum, done);
    // take
    idxs[k] = i;
    foo1(arr, n, target, i + 1, idxs, k + 1, sum + arr[i], done);
}

void problem4()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && idx == -1)
        {
            idx = i;
        }
        if (arr[i] < 0 && idx != -1)
        {
            int neg = arr[i];
            for (int j = i; j > idx; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[idx] = neg;
            idx++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void problem5()
{
    int n;
    scanf("%d", &n);
    int val[n][n];
    // int dir[n][n];
    int srow = n - 1, erow = 0, scol = n - 1, ecol = 0;
    int curr = 2 * n * n;
    while (srow > erow && scol > ecol)
    {
        for (int k = scol; k >= ecol; k--)
        {
            val[srow][k] = curr;
            curr -= 2;
            // dir[srow][k]=-2;
        }
        for (int k = srow - 1; k >= erow; k--)
        {
            val[k][ecol] = curr;
            curr -= 2;
            // dir[k][ecol]=1;
        }
        for (int k = ecol + 1; k <= scol; k++)
        {
            val[erow][k] = curr;
            curr -= 2;
            // dir[erow][k]=2;
        }
        for (int k = erow + 1; k < scol; k++)
        {
            val[k][scol] = curr;
            curr -= 2;
            // dir[k][scol]=-1;
        }
        srow--;
        scol--;
        erow++;
        ecol++;
    }
    if (n % 2 == 1)
    {
        val[n / 2][n / 2] = 2;
        // dir[n/2][n/2]=0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", val[i][j]);
        }
        printf("\n");
    }
}

void problem6()
{
    int A, B;
    scanf("%d %d", &A, &B);
    int digi[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int num = A; num <= B; num++)
    {
        if (isPrime(num))
        {
            int cpy = num;
            while (cpy > 0)
            {
                digi[cpy % 10]++;
                cpy /= 10;
            }
        }
    }
    int maxm = 0;
    int ans = -1;
    for (int i = 0; i < 10; i++)
    {
        if (digi[i] > maxm)
        {
            maxm = digi[i];
            ans = i;
        }
    }
    printf("%d %d\n", ans, maxm);
}

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void problem7()
{
    char line[1000], word[1000];
    scanf(" %[^\n]", line);
    scanf("%s", word);
    int m = (int)strlen(line), n = (int)strlen(word);
    // printf("%d %d", strlen(line), strlen(word));
    int tgt[26] = {0};
    for (int i = 0; i < n; i++)
    {
        tgt[word[i] - 'a']++;
    }
    int minWinLen = 1001;
    int minWinSt = -1;
    int minWinEnd = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (hasStrChars(line, i, j, tgt))
            {
                int currLen = j - i + 1;
                if (currLen < minWinLen)
                {
                    minWinLen = currLen;
                    minWinSt = i;
                    minWinEnd = j;
                }
            }
        }
    }
    if (minWinLen == 1001 && minWinSt == -1 && minWinEnd == -1)
    {
        printf("NO WINDOW\n");
    }
    else
    {
        printf("%d %d\n", minWinSt + 1, minWinEnd + 1);
        for (int i = minWinSt; i <= minWinEnd; i++)
        {
            printf("%c", line[i]);
        }
        printf("\n");
    }
}

bool hasStrChars(char *line, int st, int end, int *tgt)
{
    int test[26] = {0};
    for (int i = st; i <= end; i++)
    {
        if (line[i] == ' ')
            continue;
        test[line[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (test[i] < tgt[i])
        {
            return false;
        }
    }
    return true;
}

void problem8()
{
    char input[1000];
    scanf(" %[^\n]", input);
    int n = strlen(input);
    char pal[1000][1000];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        char word[1000];
        int len = 0;
        while (input[j] != ' ' && input[j] != '\0')
        {
            word[len] = input[j];
            len++;
            j++;
        }
        if (isPalindrome(word, len))
        {
            for (int i = 0; i < len; i++)
            {
                pal[x][i] = word[i];
            }
            pal[x][len] = '\0';
            x++;
        }
        i = j;
    }
    printf("\n");
    if (x == 0)
    {
        printf("NO PALINDROMES\n");
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            printf("%s ", pal[i]);
        }
        printf("\n");
    }
}
bool isPalindrome(char *word, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", word[i]);
    }
    printf(" ");
    if(len==1) return false;
    for (int i = 0; i <= len / 2; i++)
    {
        if (word[i] != word[len - i - 1])
            return false;
    }
    return true;
}