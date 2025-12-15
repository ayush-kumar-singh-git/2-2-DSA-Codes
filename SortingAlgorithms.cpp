#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void bubbleSort(int arr[], int n); // O(n^2)
void mergeSort(vector<int> &v);    // O(n log n)
void selectionSort(vector<int> &v);
void insertionSort(vector<int> &v);
vector<int> mergeSortedLists(vector<int> a, vector<int> b); // O(m+n)
vector<int> mergeSortedLists(vector<int> a, vector<int> b);
vector<int> mergeSortHelper(vector<int> arr, int start, int end);
void quickSort(vector<int> &v, int st, int end);

int main()
{
    // int arr[] = {3, 4, 5, 1, 2};
    // bubbleSort(arr, sizeof(arr) / sizeof(int));
    // for (int x : arr)
    //     cout << x << " ";
    // cout << endl;

    // vector<int> a = {3, 6, 9};
    // vector<int> b = {4, 5, 6, 7, 8};
    // vector<int> c = mergeSortedLists(a, b);
    // for (auto x : c)
    //     cout << x << " ";
    // cout << "\n";

    vector<int> v = {4, 2, 3, 4, 7, 5, 7, 6, 1};
    // mergeSort(v);
    quickSort(v, 0, v.size() - 1);
    for (int x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isSorted = true; // flag to check if the array is sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
                isSorted = false; // if a swap has been made then the array isn't sorted
            }
        }
        if (isSorted) // will remain true iff no swaps have been made in the current iteration
            break;
        // isSorted flag brings down best case time complexity to O(n) from O(n^2)
    }
    return;
}

vector<int> mergeSortedLists(vector<int> a, vector<int> b)
{
    int m = a.size();
    int n = b.size();
    vector<int> v;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            v.push_back(a[i]);
            i++;
        }
        else
        {
            v.push_back(b[j]);
            j++;
        }
    }
    for (int k = i; k < m; k++)
        v.push_back(a[k]);
    for (int k = j; k < n; k++)
        v.push_back(b[k]);
    return v;
}

void selectionSort(vector<int> &v)
{
    int unSorted = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int minm = INT_MAX;
        int minIdx = unSorted;
        for (int j = unSorted; j < n; j++)
        {
            if (v[j] < minm)
            {
                minm = v[j];
                minIdx = j;
            }
        }
        swap(v[minIdx], v[unSorted]);
        unSorted++;
    }
}

void insertionSort(vector<int> &v)
{
    int prev, curr;
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        curr = v[i];
        prev = i - 1;
        while (prev > 0 && curr < v[prev])
        {
            v[prev + 1] = v[prev];
            prev--;
        }
        v[prev] = curr;
    }
}

vector<int> mergeSortHelper(vector<int> arr, int start, int end)
{
    if (start == end)
        return vector<int>{arr[start]};
    int mid = start + (end - start) / 2;
    vector<int> left = mergeSortHelper(arr, start, mid);
    vector<int> right = mergeSortHelper(arr, mid + 1, end);
    return mergeSortedLists(left, right);
}

void mergeSort(vector<int> &v)
{
    v = mergeSortHelper(v, 0, v.size() - 1);
}

int partition(vector<int> &v, int st, int end)
{
    int idx = st - 1;
    int pivot = v[end];
    for (int j = st; j < end; j++)
    {
        if (v[j] <= pivot)
        {
            idx++;
            swap(v[idx], v[j]);
        }
    }
    idx++;
    swap(v[idx], v[end]);
    return idx;
}

void quickSort(vector<int> &v, int st, int end)
{
    if (st < end)
    {
        int pivotIdx = partition(v, st, end);
        quickSort(v, st, pivotIdx - 1);
        quickSort(v, pivotIdx + 1, end);
    }
    return;
}