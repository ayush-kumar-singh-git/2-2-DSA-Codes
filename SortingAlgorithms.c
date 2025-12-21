#include <stdio.h>
#include <limits.h>

void printArr(int *arr, int n);
void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);
void selectionSort(int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printArr(arr, n);
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