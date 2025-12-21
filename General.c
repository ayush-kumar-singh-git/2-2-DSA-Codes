#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *Array(int n)
{
    int *arr = calloc(n, sizeof(int));
    assert(arr != NULL);
    return arr;
}