#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int n);                          // O(n^2)
vector<int> mergeSortedLists(vector<int> a, vector<int> b); // O(m+n)
void mergeSort(vector<int> &v);                             // O(n log n)

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

    vector<int> v = {4, 2, 3, 5, 7, 6, 1};
    mergeSort(v);
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

void mergeSort(vector<int> &v)
{
    v = help(v, 0, v.size() - 1);
}

vector<int> help(vector<int> arr, int start, int end)
{
    if (start == end)
        return vector<int>{arr[start]};
    int mid = start + (end - start) / 2;
    vector<int> left = help(arr, start, mid);
    vector<int> right = help(arr, mid + 1, end);
    return mergeSortedLists(left, right);
}