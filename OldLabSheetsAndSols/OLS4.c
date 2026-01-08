#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ll long long
typedef struct
{
    int ff;
    int ss;
} Pair;

// gpt generated helper functions (practice later)
Pair *mergeSorted(Pair *a, Pair *b, int m, int n);
Pair *sortHelp(Pair *arr, int n);
void sort(Pair *arr, int n);

// solution functions
void problemA();
int areOverlapping(int a, int b, int c, int d);
Pair *join(int a, int b, int c, int d);
int *mergeSortedLists(int *list1, int *list2, int m, int n);
void merge(int *arr, int st, int end);
void mergeSortHelper(int *arr, int st, int end);
void mergeSort(int *arr, int n);
void problemB();
int numberOfElementsGreaterThanorEq(int *arr, int n, int tgt);
int countTrailingZeros(int n);
ll nC2(int n);
void problemC();
int largestIdxEqToTgt(int *arr, int st, int n, int tgt);
int *sieve(int n);
void problemD();
void problemE();
int gcd(int a, int b);
int max(int a, int b);
void problemF();
void radixSort(int *arr, int n);
void countSort(int *arr, int n, int k); // (n/k)%10
void problemG();
void printArr(int *arr, int n);
void problemH();
void problemI();
void problemJ();
int min(int a, int b);

int main()
{
    // int T;
    // scanf("%d", &T);
    // while (T--)
    problemJ();
    return 0;
}

Pair *mergeSorted(Pair *a, Pair *b, int m, int n)
{
    Pair *res = malloc((m + n) * sizeof(Pair));
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (a[i].ff < b[j].ff ||
            (a[i].ff == b[j].ff && a[i].ss <= b[j].ss))
            res[k++] = a[i++];
        else
            res[k++] = b[j++];
    }

    while (i < m)
        res[k++] = a[i++];
    while (j < n)
        res[k++] = b[j++];

    return res;
}

Pair *sortHelp(Pair *arr, int n)
{
    if (n == 1)
    {
        Pair *base = malloc(sizeof(Pair));
        base[0] = arr[0];
        return base;
    }

    int mid = n / 2;
    Pair *left = sortHelp(arr, mid);
    Pair *right = sortHelp(arr + mid, n - mid);

    Pair *merged = mergeSorted(left, right, mid, n - mid);

    free(left);
    free(right);

    return merged;
}

void sort(Pair *arr, int n)
{
    Pair *sorted = sortHelp(arr, n);
    for (int i = 0; i < n; i++)
        arr[i] = sorted[i];
    free(sorted);
}

void problemA()
{
    int n;
    scanf("%d", &n);
    Pair list[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &list[i].ff, &list[i].ss);
    }
    sort(list, n);
    Pair ans[100]; // change if constraints are big
    int k = 0;
    int l = list[0].ff, r = list[0].ss;
    for (int i = 1; i < n; i++)
    {
        if (areOverlapping(l, r, list[i].ff, list[i].ss))
        {
            Pair *joined = join(l, r, list[i].ff, list[i].ss);
            l = joined->ff;
            r = joined->ss;
        }
        else
        {
            ans[k].ff = l;
            ans[k].ss = r;
            k++;
            l = list[i].ff;
            r = list[i].ss;
        }
    }
    if ((k == 0) || !(ans[k - 1].ff == l && ans[k - 1].ss == r))
    {
        ans[k].ff = l;
        ans[k].ss = r;
        k++;
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d %d\n", ans[i].ff, ans[i].ss);
    }
}

int areOverlapping(int a, int b, int c, int d)
{
    if (a < c && a < d && b < c && b < d)
        return FALSE;
    if (c < a && c < b && d < a && d < b)
        return FALSE;
    return TRUE;
}

Pair *join(int a, int b, int c, int d)
{
    Pair *joined = malloc(sizeof(Pair));
    joined->ff = a < c ? a : c;
    joined->ss = b > d ? b : d;
    return joined;
}

int *mergeSortedLists(int *list1, int *list2, int m, int n)
{
    int *mergedList = calloc(m + n, sizeof(int));
    if (mergedList == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (list1[i] <= list2[j])
        {
            mergedList[k] = list1[i];
            i++;
        }
        else
        {
            mergedList[k] = list2[j];
            j++;
        }
        k++;
    }
    for (int x = i; x < m; x++)
    {
        mergedList[k] = list1[x];
        k++;
    }
    for (int x = j; x < n; x++)
    {
        mergedList[k] = list2[x];
        k++;
    }

    return mergedList;
}

void merge(int *arr, int st, int end)
{
    int mid = st + (end - st) / 2;

    int m = mid - st + 1;
    int n = end - mid;

    int *merged = mergeSortedLists(arr + st, arr + mid + 1, m, n);
    if (merged == NULL)
        return;

    for (int i = 0; i < m + n; i++)
    {
        arr[st + i] = merged[i];
    }

    free(merged);
}

void mergeSortHelper(int *arr, int st, int end)
{
    if (st >= end)
        return;
    int mid = st + (end - st) / 2;
    mergeSortHelper(arr, st, mid);
    mergeSortHelper(arr, mid + 1, end);
    merge(arr, st, end);
}

void mergeSort(int *arr, int n)
{
    mergeSortHelper(arr, 0, n - 1);
}

void problemB()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, n);
    int ans = -1;
    int l = 0, r = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (numberOfElementsGreaterThanorEq(arr, n, mid) >= mid)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
}

int numberOfElementsGreaterThanorEq(int *arr, int n, int tgt)
{
    int idx = n;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= tgt)
        {
            idx = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return n - idx;
}

int countTrailingZeros(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += (n / 5);
        n /= 5;
    }
    return ans;
}

ll nC2(int n)
{
    if (n == 1)
        return 0;
    ll ans = n;
    ans = n * (n - 1);
    ans = ans / 2;
    return ans;
}

int largestIdxEqToTgt(int *arr, int st, int n, int tgt)
{
    int l = st, r = n - 1;
    int ans = st;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] <= tgt)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

void problemC()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = countTrailingZeros(arr[i]);
    }
    ll ans = 0;
    int idx = 0;
    while (idx < n)
    {
        int endIdx = largestIdxEqToTgt(arr, idx, n, arr[idx]);
        ans += (nC2(endIdx - idx + 1));
        idx = endIdx;
        idx++;
    }
    printf("%lld\n", ans);
}

int *sieve(int n)
{
    int *isPrime = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
        isPrime[i] = 1;

    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
    return isPrime;
}

void problemD()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int *isPrime = sieve(n);
    for (int i = 1; i <= n; i++)
    {
        isPrime[i] += isPrime[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        int Q;
        scanf("%d", &Q);
        printf("%d ", isPrime[Q]);
    }
    printf("\n");
}

void problemE()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    for (int d = 1; d * d <= a; d++)
    {
        if (a % d == 0)
        {
            int d1 = d, d2 = a / d;
            if (gcd(d1, b) == 1)
            {
                ans = max(ans, d1);
            }
            if (gcd(d2, b) == 1)
            {
                ans = max(ans, d2);
            }
        }
    }
    printf("%d\n", ans);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void problemF()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, n);
    Pair list[100000]; // increase if necessary
    int idx = 0;
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n && arr[j] == arr[i])
        {
            j++;
        }
        list[idx].ff = j - i;
        list[idx].ss = arr[i];
        i = j;
        idx++;
    }
    sort(list, idx);
    for (int j = idx - 1; j >= idx - k; j--)
    {
        printf("%d ", list[j].ss);
    }
    printf("\n");
}

void problemG()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    radixSort(arr, n);
    return;
}

void radixSort(int *arr, int n)
{
    int maxm = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxm = max(arr[i], maxm);
    }
    int k = 1;
    while (maxm / k > 0)
    {
        countSort(arr, n, k);
        printArr(arr, n);
        k *= 10;
    }
    return;
}
void countSort(int *arr, int n, int k)
{
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / k) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    int cpy[n];
    for (int i = n - 1; i >= 0; i--)
    {
        cpy[count[(arr[i] / k) % 10] - 1] = arr[i];
        count[(arr[i] / k) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = cpy[i];
    }
    return;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void problemH()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll maxm = nC2(n - m + 1);
    ll k = n / m;
    ll left = n - (m * k);
    ll minm = left * nC2(k + 1) + (m - left) * nC2(k);
    printf("%lld %lld\n", minm, maxm);
}

void problemI()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if (n == 1)
    {
        printf("0\n");
        return;
    }
    int pgcd[n], sgcd[n];
    pgcd[0] = arr[0];
    sgcd[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        pgcd[i] = gcd(pgcd[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        sgcd[i] = gcd(sgcd[i + 1], arr[i]);
    }
    int ans = max(sgcd[1], pgcd[n - 2]);
    for (int i = 1; i < n - 1; i++)
    {
        ans = max(ans, gcd(pgcd[i - 1], sgcd[i + 1]));
    }
    printf("%d\n", ans);
}

void problemJ()
{
    // using mean is wrong fails the following
    // 5
    // 1 2 100 101 102
    // use median instead or bin search
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // ll k = sum / n;
    // ll ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     ans += abs(k - arr[i]);
    // }
    // printf("%lld\n", ans);
    mergeSort(arr, n);
    int median = arr[n / 2];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(median - arr[i]);
    }
    printf("%lld\n", ans);
}

/*
    Learn about convex and concave functions and binary search on them
*/