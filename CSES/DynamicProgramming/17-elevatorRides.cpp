#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// O(n * n!) approach
ll ans = LONG_LONG_MAX;
ll calls = 0;
void solve(vector<ll> &v, ll x, ll cur, ll k)
{
    calls++;
    cout << cur << ", " << k << endl;
    int n = v.size();
    if (k >= ans)
        return;
    bool allMinusOne = true;
    for (int j = 0; j < n; j++)
    {
        if (v[j] != -1)
        {
            allMinusOne = false;
            int temp = v[j];
            v[j] = -1;
            if (cur + temp <= x)
            {
                solve(v, x, cur + temp, k);
            }
            else
            {
                solve(v, x, temp, k + 1);
            }
            v[j] = temp;
        }
    }
    if (allMinusOne)
    {
        ans = min(ans, k);
    }
}

// O(n * 2 ^ n) approach using DP
int solveBU(vector<ll> &v, int x)
{
    int n = v.size();
    vector<pair<int, ll>> dp((1 << n));
    dp[0] = {1, 0};

    int N = 1 << n;
    for (int i = 1; i < N; i++)
    {
        dp[i] = {n + 1, 0};
        for (int j = 0; j < n; j++)
        {
            int ns = i ^ (1 << j);
            if (i & (1 << j))
            {
                pair<int, ll> option = dp[ns];
                if (dp[ns].second + v[j] > x)
                {
                    option.first++;
                    option.second = v[j];
                }
                else
                {
                    option.second += v[j];
                }
                dp[i] = min(dp[i], option);
            }
        }
    }
    return dp[N - 1].first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;

    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;

        v.push_back(t);
    }

    // solve(v, x, 0, 1);
    // cout << ans << endl;
    // cout << calls << endl;
    cout << solveBU(v, x) << endl;
    return 0;
}