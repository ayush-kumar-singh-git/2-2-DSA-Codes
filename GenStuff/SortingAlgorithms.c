#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n);
void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);
void selectionSort(int *arr, int n);
int *mergeSortedLists(int *list1, int *list2, int m, int n);
void merge(int *arr, int st, int end); // kind of redundant but I like it this way
void mergeSortHelper(int *arr, int st, int end);
void mergeSort(int *arr, int n); // Just a wrapper
void quickSort(int *arr, int n); // Just a wrapper
void quickSortHelper(int *arr, int st, int end);
int partition(int *arr, int st, int end);

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, n);
    printArr(arr, n);
    free(arr);
    return 0;
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void bubbleSort(int *arr, int n)
{
    int swapped;
    for (int i = 0; i < n; i++)
    {
        swapped = 0;
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    return;
}

void insertionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        int val = arr[j];
        while (j > 0 && val < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = val;
    }
    return;
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minm = arr[i];
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < minm)
            {
                minm = arr[j];
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
    return;
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

int partition(int *arr, int st, int end)
{
    int pivot = arr[end];
    int pivotIdx = end;
    int i = st - 1;
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);
    return i + 1;
}

void quickSortHelper(int *arr, int st, int end)
{
    if (st < end)
    {
        int p = partition(arr, st, end);
        quickSortHelper(arr, st, p - 1);
        quickSortHelper(arr, p + 1, end);
    }
}

void quickSort(int *arr, int n)
{
    quickSortHelper(arr, 0, n - 1);
}