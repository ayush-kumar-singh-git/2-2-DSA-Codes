#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

#define ll long long

void problemA(); // this is wrong
void problemB();
void problemD();

int main()
{
    problemD();
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

void problemB()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> prevC(n), nextC(n), ps(n + 1, 0);
    int curr = -1;
    for (int i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + (s[i] == '*');
        curr = s[i] == '|' ? i : curr;
        prevC[i] = curr;
    }
    curr = n;
    for (int i = n - 1; i >= 0; i--)
    {
        curr = s[i] == '|' ? i : curr;
        nextC[i] = curr;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        assert(l >= 0 && r < n);
        if (nextC[l] == n || prevC[r] == -1)
        {
            cout << 0 << "\n";
        }
        else
        {
            int a = nextC[l];
            int b = prevC[r];
            cout << ps[b] - ps[a + 1] << "\n";
        }
    }
}

void problemD(){
    int n;
    long double k;
    cin>>n>>k;
    vector<long double>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]-=k;
    }
    map<long double, int>mp;
    mp[0]=1;
    int answer = 0;
    long double sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        answer+=(mp[sum]);
        mp[sum]++;
    }
    cout<<answer<<"\n";
}