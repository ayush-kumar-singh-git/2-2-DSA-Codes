#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *Array(int n)
{
    int *arr = calloc(n, sizeof(int));
    assert(arr != NULL);
    return arr;
}

int* sieve(int n)
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