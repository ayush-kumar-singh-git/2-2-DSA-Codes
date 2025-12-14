#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

vector<vector<int>> matrixMultiplication(vector<vector<int>> &M1, vector<vector<int>> &M2)
{
    int a = M1.size();
    int b = M1[0].size();
    int c = M2[0].size();
    if (b != M2.size())
    {
        cout << "Incompatible Matrices";
        return {{}};
    }
    vector<vector<int>> M(a, vector<int>(c, 0));
    // TC O(a*b*c) = O(n^3)
    // SC O(a*c) = O(n^2)
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int curr = 0;
            for (int k = 0; k < b; k++)
            {
                curr += M1[i][k] * M2[k][j];
            }
            M[i][j] = curr;
        }
    }
    return M;
}

int linearSearch(vector<int> &v, int target)
{
    // TC O(n)
    // SC O(1)
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
            return i; // returning index if found
    }
    return -1; // if not found
}

int binarySearch(vector<int> &v, int target)
{
    // assuming the input is sorted
    //  TC O(log n)
    //  SC O(1)
    int lo = 0, hi = v.size();
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        else if (v[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}

// recursive algorithm
// TC O(2^n)
// SC O(n)
int fib1(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib1(n - 1) + fib1(n - 2);
}

// recursive + memoization
// TC O(n)
// SC O(n)
int fib2(int n, unordered_map<int, int> &memo)
{
    if (memo.find(n) != memo.end())
        return memo[n];
    if (n == 0)
        return memo[0] = 0;
    if (n == 1)
        return memo[1] = 1;
    return memo[n] = fib2(n - 1, memo) + fib2(n - 2, memo);
}

// Iterative
//  TC O(n)
//  SC O(1)
int fib3(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev = 0;
    int curr = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = curr + prev;
        prev = curr;
        curr = temp;
    }
    return curr;
}

vector<pair<int, int>> schedulingOfTasks(vector<pair<int, int>> &stEnd)
{
    vector<pair<int, int>> ans;
    // O(nlogn) for sorting
    sort(stEnd.begin(), stEnd.end(), [](auto &a, auto &b)
         {
        if(a.second!=b.second) return a.second < b.second;
        return a.first < b.first; });
    int end = INT_MIN;
    // O(n) for iterating
    for (auto p : stEnd)
    {
        if (p.first >= end)
        {
            ans.push_back(p);
            end = p.second;
        }
    }
    return ans;
}

int determinant(vector<vector<int>>&M, int leftx){
    // assuming input is valid
}

int main()
{
    cout<<fib1(10)<<"\n";
    unordered_map<int,int>mp;
    cout<<fib2(10, mp)<<"\n";
    cout<<fib3(10)<<"\n";
    return 0;
}