#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Top down dp soln, O(n ^ 2) TC
map<pair<int, int>, int> m;
ll solve(vector<pair<pair<int, int>, int>> &v, int cur, int e)
{
    int n = v.size();
    if (cur >= n)
        return 0;
    if (m.find({cur, e}) != m.end())
    {
        return m[{cur, e}];
    }

    ll ans = 0;
    if (v[cur].first.second > e)
    {
        ans = max(ans, v[cur].second + solve(v, cur + 1, v[cur].first.first));
    }
    ans = max(ans, solve(v, cur + 1, e));
    return m[{cur, e}] = ans;
}

// O(n ^ 2) bottom up soln based on LIS
ll solveBU(vector<pair<pair<int, int>, int>> &v)
{
    int n = v.size();
    vector<ll> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = v[i].second;
    }

    ll ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].first.second > v[j].first.first)
            {
                dp[i] = max(dp[i], v[i].second + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

bool cmp(pair<pair<int, int>, int> f, pair<pair<int, int>, int> s)
{
    if (f.first.first == s.first.first)
    {
        if (f.first.second == s.first.second)
            return f.second < s.second;
        return f.first.second < s.first.second;
    }
    return f.first.first < s.first.first;
}

// O(n * log n) top-down solution
map<int, ll> m2;
ll solveTD2(vector<pair<pair<int, int>, int>> &v, int cur)
{
    if (cur < 0)
        return 0;
    if (m2.find(cur) != m2.end())
        return m2[cur];

    ll ans = 0;

    int idx = lower_bound(v.begin(), v.begin() + cur, make_pair(make_pair(v[cur].first.second, INT_MIN), INT_MIN), cmp) - v.begin();
    idx--;
    ll temp = solveTD2(v, idx);
    ans = max(ans, v[cur].second + temp);
    ans = max(ans, solveTD2(v, cur - 1));
    return (m2[cur] = ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.second >> v[i].first.first >> v[i].second;
    }
    sort(v.begin(), v.end());

    cout << solveTD2(v, n - 1) << endl;
    return 0;
}