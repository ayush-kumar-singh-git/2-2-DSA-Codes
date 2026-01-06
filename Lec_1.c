#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Adding TWO BIG NUMBERS in O(n)
void addBigNum();
int max(int a, int b);
void std(char *s, int m, int n);                      // m = curr size, n = required size, padding
int add(char *num1, char *num2, char *result, int n); // it will return the size of the final number(result)
void reverse(char *s, int n);

// given path in a graph checking if it is valid and hamilton
int checkHamilton();

int main()
{
    // addBigNum();
    // checkHamilton();
    return 0;
}

void addBigNum()
{
    int m, n;
    char one[1000], two[1000];
    scanf("%d", &m);
    scanf("%s", one);
    scanf("%d", &n);
    scanf("%s", two);
    int mx = max(m, n);
    reverse(one, m);
    reverse(two, n);
    std(one, m, mx);
    std(two, n, mx);
    char ans[1000];
    int k = add(one, two, ans, mx);
    reverse(ans, k);
    printf("%s\n", ans);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void std(char *s, int m, int n)
{
    if (m == n)
        return;
    for (int i = m; i < n; i++)
    {
        s[i] = '0';
    }
    s[n] = '\0';
    return;
}

int add(char *num1, char *num2, char *result, int n)
{
    int k = 0;
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int one = num1[i] - '0';
        int two = num2[i] - '0';
        int tot = one + two + carry;
        int digi = tot;
        carry = digi / 10;
        digi %= 10;
        result[k] = (digi + '0');
        k++;
    }
    if (carry > 0)
    {
        result[k] = (carry + '0');
        k++;
    }
    result[k] = '\0';
    return k;
}

void reverse(char *s, int n)
{
    char ch;
    for (int i = 0; i <= n / 2; i++)
    {
        ch = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = ch;
    }
}

int checkHamilton()
{
    int n; // number of vertices
    scanf("%d", &n);
    int e; // number of edges
    scanf("%d", &e);
    // assuming undirected
    int graph[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            graph[i][j] = FALSE;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int e1, e2;
        scanf("%d %d", &e1, &e2);
        graph[e1][e2] = TRUE;
        graph[e2][e1] = TRUE;
    }

    int q; // number of paths to check
    scanf("%d", &q);
    while (q--)
    {
        int m; // size of path;
        scanf("%d", &m);
        int path[m];
        for (int i = 0; i < m; i++)
            scanf("%d", &path[i]);
        int ok = TRUE;
        if (path[0] != path[m - 1])
        {
            ok = FALSE;
        }
        int vis[n + 1];
        for (int i = 1; i <= n; i++)
            vis[i] = FALSE;
        vis[path[0]] = TRUE;
        if (ok)
        {
            for (int i = 1; i < m; i++)
            {
                if (graph[path[i]][path[i - 1]] == FALSE)
                {
                    ok = FALSE;
                    break;
                }
                if (i != m - 1 && vis[path[i]])
                {
                    ok = FALSE;
                    break;
                }
                vis[path[i]] = TRUE;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ok = FALSE;
                break;
            }
        }
        if (ok)
            printf("Valid\n");
        if (!ok)
            printf("Not Valid\n");
    }
}