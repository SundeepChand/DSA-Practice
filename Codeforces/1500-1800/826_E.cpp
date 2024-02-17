#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool solve(const vector<int> &v, int i)
{
    int n = v.size();
    if (i == n)
        return true;
    if (i > n)
        return false;

    bool ans = solve(v, i + 1 + v[i]);
    for (int j = i + 1; !ans and j < n; j++)
    {
        if (v[j] == j - i)
            ans = ans || solve(v, j + 1);
    }
    return ans;
}

bool solve2(const vector<int> &v)
{
    int n = v.size();

    vector<bool> dp(n + 1, false);
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--)
    {
        int cur = v[i];
        if (i + 1 + cur <= n and dp[i + 1 + cur])
            dp[i] = true;
        if (dp[i + 1] and i - cur >= 0)
            dp[i - cur] = true;
    }
    return dp[0];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    /*

    9
    1 1 2 3 1 3 2 2 3
    T     T   T       T
    */

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (solve2(v))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}