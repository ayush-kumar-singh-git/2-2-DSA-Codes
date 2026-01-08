/*

    DIDNOT SOLVE B AND C AND J - NOOBISH BEHAVIOUR

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ll long long
void problemA();
void helperA(int open, int close, int n, char curr[], int i, char list[][n + 1], int *idx);
void problemB(); // didnot solve
ll helperB(ll st, ll end, ll step, ll dir);
void problemC(); // my solution is wrong
bool ok(int *arr, int n);
void problemD();
void problemEsol1(); // O(n^2) sol
void problemEsol2(); // completely wrong
void problemE();     // this is the correct O(n) solution
void problemF();     // I am proud of myself :')
void problemG();
void helperG();
int max(int a, int b);
int min(int a, int b);
void problemH();
void problemI();

int main()
{
    // int T;
    // scanf("%d", &T);
    // while (T--)
    problemI();
    return 0;
}

void problemA()
{
    int n;
    scanf("%d", &n);
    char list[1000][n + 1];
    int idx = 0;
    char curr[20];
    helperA(0, 0, n, curr, 0, list, &idx);
    printf("%d\n", idx);
    for (int i = 0; i < idx; i++)
    {
        printf("%s\n", list[i]);
    }
}

void helperA(int open, int close, int n, char curr[], int i, char list[][n + 1], int *idx)
{
    if (open > n / 2 || close > open)
        return;
    if (i == n)
    {
        if (open != close && open + close != n)
            return;
        for (int i = 0; i < n; i++)
        {
            list[*idx][i] = curr[i];
        }
        list[*idx][n] = '\0';
        (*idx)++;
        return;
    }
    if (open < n / 2)
    {
        curr[i] = '(';
        helperA(open + 1, close, n, curr, i + 1, list, idx);
    }
    if (close < open)
    {
        curr[i] = ')';
        helperA(open, close + 1, n, curr, i + 1, list, idx);
    }
}

void problemB()
{
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", helperB(1, n, 1, 1));
}

ll helperB(ll st, ll end, ll step, ll dir)
{
}

void problemC()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char str[n];
    scanf("%s", str);
    int i = 0;
    int freq[k];
    for (int j = 0; j < k; j++)
        freq[j] = 0;
    while (i < k)
    {
        freq[str[i] - 'a']++;
        i++;
    }
    int ans = 0;
    int left = n - k;
    if (ok(freq, k))
        ans += (left + 1);
    int st = 0;
    while (i < n)
    {
        left--;
        char c = str[i];
        freq[str[st] - 'a']--;
        freq[str[i] - 'a']++;
        if (ok(freq, k))
            ans += (left + 1);
        st++;
        i++;
    }
    printf("%d\n", ans);
}

bool ok(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
            return false;
    }
    return true;
}

void problemD()
{
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);
    ll lim = (ll)k * t;
    ll sum = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ll ans = sum >= lim ? 1 : 0;
    int st = 0;
    for (int i = k; i < n; i++)
    {
        sum -= arr[st];
        sum += arr[i];
        if (sum >= lim)
            ans++;
        st++;
    }
    printf("%lld\n", ans);
}

void problemEsol1()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = 0, cost = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        cost = 0;
        while (j < n)
        {
            if (arr[j] == 0)
            {
                if (cost == k)
                    break;
                cost++;
            }
            j++;
        }
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void problemEsol2()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int dp[n];
    int i = 0;
    int cost = 0;
    dp[0] = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            if (cost == k)
                break;
            cost++;
        }
        i++;
        dp[0]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i - 1] == 0)
        {
            dp[i] = dp[i - 1] - 1;
            int j = i - 1 + dp[i];
            int curr = 0;
            while (j < n)
            {
                if (arr[j] == 0)
                {
                    if (curr == 1)
                        break;
                    curr++;
                }
                j++;
                dp[i]++;
            }
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}

void problemE()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    int l = 0, zeros = 0;
    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
            zeros++;
        while (zeros > k)
        {
            if (arr[l] == 0)
                zeros--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
}

void problemF()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int m;
    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }
    int a = A[0], b = B[0];
    for (int i = 1; i < n; i++)
        a = (a ^ A[i]);
    for (int i = 1; i < m; i++)
        b = (b ^ B[i]);
    int ans = 0;
    if (m % 2 == 0)
    {
        if (n % 2 == 0)
        {
            ans = 0;
        }
        else
        {
            ans = b;
        }
    }
    else
    {
        if (n % 2 == 0)
        {
            ans = a;
        }
        else
        {
            ans = a ^ b;
        }
    }
    printf("%d\n", ans);
}

void problemG()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int dis[k];
    for (int i = 0; i < k; i++)
        dis[i] = 0;
    int ans = 1e9;
    helperG(arr, n, 0, dis, k, &ans);
    printf("%d\n", ans);
}
void helperG(int *arr, int n, int i, int *dis, int k, int *ans)
{
    if (i == n)
    {
        ll curr = 0;
        for (int j = 0; j < k; j++)
        {
            curr = max(curr, dis[j]);
        }
        *ans = min(*ans, curr);
        return;
    }
    for (int per = 0; per < k; per++)
    {
        dis[per] += arr[i];
        helperG(arr, n, i + 1, dis, k, ans);
        dis[per] -= arr[i]; // backtracing
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void problemH()
{
    int n, k;
    scanf("%d %d", &n, &k);
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int *freq = (int *)calloc(k, sizeof(int));
    arr[0] = (arr[0]) % k;
    freq[arr[0]]++;
    for (int i = 1; i < n; i++)
    {
        arr[i] = (arr[i] + arr[i - 1]) % k;
        freq[arr[i]]++;
    }
    ll ans = freq[0];
    // can be done using nC2 for each remainder :)
    // for (int i = 0; i < n; i++)
    // {
    //     freq[arr[i]]--;
    //     if (arr[i] == 0)
    //     {
    //         ans += (1 + freq[arr[i]]);
    //     }
    //     else
    //     {
    //         ans += (freq[arr[i]]);
    //     }
    // }
    for (int i = 0; i < k; i++)
    {
        ans += (freq[i] * (freq[i] - 1)) / 2; // basically nc2
    }
    printf("%lld\n", ans);
}

void problemI()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] = (arr[i] % 2);
        arr[i] += arr[i - 1];
    }
    ll freq[n + 1];
    for (int i = 0; i <= n; i++)
        freq[i] = 0;

    freq[0] = 1;

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] - k >= 0)
            ans += freq[arr[i] - k];

        freq[arr[i]]++;
    }
    printf("%lld\n", ans);
}