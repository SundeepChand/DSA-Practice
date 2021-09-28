#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// map<pair<int, ll>, ll> dp;
ll solve(const vector<int> &v, int i, ll cur, const ll &sum)
{
    if (i < 0)
        return abs(sum - 2 * cur);

    // if (dp.find({i, cur}) != dp.end())
    // {
    //     return dp[{i, cur}];
    // }

    ll a = solve(v, i - 1, cur, sum);
    ll b = solve(v, i - 1, cur + v[i], sum);

    // if (a < b)
    //     return dp[{i, cur}] = a;
    // return dp[{i, cur}] = b;

    if (a < b)
        return a;
    return b;
}

ll solve2(const vector<int> &v, int i, ll cur, const ll &sum)
{
    if (i < 0)
        return abs(sum - 2 * cur);
    return min(solve2(v, i - 1, cur, sum), solve2(v, i - 1, cur + v[i], sum));
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    cout << solve2(v, n - 1, 0, sum) << endl;
    return 0;
}