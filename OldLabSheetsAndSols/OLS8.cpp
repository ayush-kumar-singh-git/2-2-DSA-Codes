#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

void problemA();
string helperA(string s);
void problemB(); // pending
void problemC();
void problemD();
void problemE();
void problemF(); // pending
void problemG(); // pending
void problemH();
void problemI();
void problemJ();

int main()
{
    problemF();
    return 0;
}

string helperA(string s)
{
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (char c : s)
    {
        arr[c - 'a']++;
    }
    string ret = "";
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            ret += string(i + 'a', arr[i]);
        }
    }
    return ret;
}

void problemA()
{
    // not of the intended time complexity
    // this solution has O(mnlogm + nlogn) if we sort using sort()
    // sorting using helper gets the required time complexity
    map<string, int> mp;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        // sort(s.begin(), s.end()); // O(m log m)
        s = helperA(s); // O(m)
        mp[s]++;        // O(log n)
    }
    ll ans = 0;
    for (auto p : mp) // O(n)
    {
        ans += (((ll)p.second * (p.second - 1)) / 2);
    }
    cout << ans << "\n";
}

void problemC()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) // O(n) input ignored
    {
        cin >> v[i];
    }
    int x, y;
    cin >> x >> y;
    map<int, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) // O(n * log n)
    {
        int ii = x * i - v[i];
        int jj = y * i - v[i];
        ans += mp[jj];
        mp[ii]++;
    }
    cout << ans << "\n";
}

void problemD()
{
    int n, q;
    cin >> n >> q;
    set<int> st; // stores 1 based indices which are currently 1
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        switch (a)
        {
        case 1:
        {
            if (st.find(b) != st.end())
                st.erase(b);
            else
                st.insert(b);
            break;
        }
        case 2:
        {
            auto it = st.lower_bound(b); // can manually implement this but why
            if (it == st.end())
                cout << -1 << "\n";
            else
                cout << *it << "\n";
            break;
        }
        case 3:
        {
            auto it = st.upper_bound(b); // can manually implement this but why
            if (it == st.begin())
                cout << -1 << "\n";
            else
            {
                it--;
                cout << *it << "\n";
            }
            break;
        }
        }
    }
}

void problemE()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, int> freq;
    set<int> st;
    int l = 0;
    for (int i = 0; i < m; i++)
    {
        freq[v[i]]++;
        if (freq[v[i]] == k)
        {
            st.insert(v[i]);
        }
        else
        {
            st.erase(v[i]);
        }
    }
    if (st.empty())
    {
        cout << "-1\n";
    }
    else
    {
        auto it = st.end();
        it--;
        cout << *it << "\n";
    }
    for (int r = m; r < n; r++)
    {
        freq[v[l]]--;
        freq[v[r]]++;
        if (freq[v[l]] == k)
        {
            st.insert(v[l]);
        }
        else
        {
            st.erase(v[l]);
        }
        if (freq[v[r]] == k)
        {
            st.insert(v[r]);
        }
        else
        {
            st.erase(v[r]);
        }
        l++;
        if (st.empty())
        {
            cout << "-1\n";
        }
        else
        {
            auto it = st.end();
            it--;
            cout << *it << "\n";
        }
    }
    return;
}

void problemF()
{
    // we can optimize space as we don't need px at all one curr var is enough
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // vector<int> px(n + 1, 0);
    map<int, ll> mp;
    int ans = 0;
    mp[0] = 1;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        // px[i + 1] = (px[i] ^ v[i]);
        curr = (curr ^ v[i]);
        ans += mp[curr];
        mp[curr]++;
    }

    cout << ans << "\n";
}

void problemH()
{
    string s;
    cin >> s;
    string curr = "";
    int n = s.size();
    if (n < 10)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        curr += s[i];
    }
    map<string, int> mp;
    mp[curr]++;
    int l = 0;
    for (int r = 10; r < n; r++)
    {
        for (int i = 1; i < 10; i++)
        {
            curr[i - 1] = curr[i];
        }
        curr[9] = s[r];
        l++;
        mp[curr]++;
    }
    set<string> answers;
    for (auto p : mp)
    {
        if (p.second > 1)
        {
            answers.insert(p.first);
        }
    }
    cout << answers.size() << "\n";
    for (auto str : answers)
    {
        cout << str << "\n";
    }
}

void problemI()
{
    // can be done in O(n) only
    int n, k;
    cin >> n >> k;
    vector<int> v(k + 1, 0); // just tracks the losses as only they matter
    for (int i = 0; i < n; i++)
    {
        int w, l;
        cin >> w >> l;
        v[l]++;
    }
    for (int i = 1; i <= k; i++)
    {
        if (v[i] <= 1)
            cout << i << " ";
    }
    cout << "\n";

    // O(nlogn) uses map for the same thing just as follows:
    /*
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int w,l;
            cin>>w>>l;
            mp[l]++;
        }
        for(int i=1;i<=k;i++){
            if(mp[i]<=1) cout<<i<<" ";
        }
        cout<<"\n";
    */
}

void problemJ()
{
    int n, k;
    cin >> n >> k;
    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        ps[i] = ps[i - 1] + temp;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tgt = ps[i - 1] + k + 1;
        int j = lower_bound(ps.begin(), ps.end(), tgt) - ps.begin() - 1;
        ans += max(0, j - i + 1);
    }
    cout << ans << "\n";

    // O(n) is also possible
    /*

        ll ans = 0;
        int l = 0, ones = 0;

        for (int r = 0; r < n; r++)
        {
            if (a[r] == 1)
                ones++;

            while (ones > k)
            {
                if (a[l] == 1)
                    ones--;
                l++;
            }

            ans += (r - l + 1);
        }

    */
}