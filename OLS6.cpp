#include <iostream>
#include <stack>
#include <deque>
#include <string>

#define ll long long

void problemB();
void problemC();
ll max(ll a, ll b);
void problemE();
void problemG();
void problemI();
void problemJ();

int main()
{
    problemJ();
    return 0;
}

void problemB()
{
    // basically next greater in a cycle
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::stack<int> stk;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
        {
            stk.pop();
        }
        stk.push(i);
    }
    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
        {
            stk.pop();
        }
        if (stk.empty() || stk.top() == i)
        {
            ans[i] = -1;
        }
        else
        {
            if (stk.top() < i)
            {
                ans[i] = n + stk.top() - i;
            }
            else
            {
                ans[i] = stk.top() - i;
            }
        }
        stk.push(i);
    }
    for (int x : ans)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return;
}

void problemC()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::stack<int> prevSmaller, nextSmaller; // can just reuse first stk but lite
    int pidx[n], nidx[n];
    for (int i = 0; i < n; i++)
    {
        while (!prevSmaller.empty() && arr[prevSmaller.top()] >= arr[i])
        {
            prevSmaller.pop();
        }
        if (prevSmaller.empty())
            pidx[i] = -1;
        else
            pidx[i] = prevSmaller.top();
        prevSmaller.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!nextSmaller.empty() && arr[nextSmaller.top()] >= arr[i])
        {
            nextSmaller.pop();
        }
        if (nextSmaller.empty())
            nidx[i] = n;
        else
            nidx[i] = nextSmaller.top();
        nextSmaller.push(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll currArea = (ll)arr[i] * (nidx[i] - pidx[i] - 1);
        ans = max(ans, currArea);
    }
    std::cout << ans << "\n";
}

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

void problemE()
{
    int n, k;
    std::cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int r = k; r < n; r++)
    {
        std::cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= r - k)
            dq.pop_front();
        while (dq.size() > 0 && arr[dq.back()] <= arr[r])
            dq.pop_back();
        dq.push_back(r);
    }
    std::cout << arr[dq.front()] << "\n";
}

void problemG()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
        {
            stk.pop();
        }
        if (stk.empty())
            std::cout << i + 1 << " ";
        else
            std::cout << i - stk.top() << " ";
        stk.push(i);
    }
    std::cout << "\n";
}

void problemI()
{
    std::string s;
    std::cin >> s;
    std::stack<std::string> stk;
    int i = 0;
    int n = s.size();
    while (i < n)
    {
        if (s[i] == '/')
        {
            i++;
            continue;
        }
        std::string curr = "";
        curr += s[i];
        int j = i + 1;
        while (j < n && s[j] != '/')
        {
            curr += s[j];
            j++;
        }
        if (curr == ".")
        {
            i = j;
            continue;
        }
        if (curr == "..")
        {
            if (!stk.empty())
                stk.pop();
            i = j;
            continue;
        }
        stk.push(curr);
        i = j;
    }
    std::string ans = "";
    while (!stk.empty())
    {
        ans = "/" + stk.top() + ans;
        stk.pop();
    }
    if (ans.size() == 0)
    {
        std::cout << "/";
    }
    else
    {
        for (auto c : ans)
        {
            std::cout << c;
        }
    }
    std::cout << "\n";
}

void problemJ()
{
    std::string s;
    std::cin >> s;
    std::stack<char> stk;
    int answer = 0;
    for (char c : s)
    {
        if (c == ')')
        {
            if (stk.empty() || stk.top() != '(')
                answer++;
            if (!stk.empty())
                stk.pop();
        }
        else
        {
            stk.push(c);
        }
    }
    while (!stk.empty())
    {
        answer++;
        stk.pop();
    }
    std::cout << answer << "\n";
}