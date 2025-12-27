#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void problemA();

int main()
{
    problemA();
    return 0;
}

void problemA()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());
    int ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum >= 0)
            ans++;
        else
            break;
    }
    cout << ans << "\n";
}