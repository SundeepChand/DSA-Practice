// https://www.spoj.com/problems/MIXTURES/
// Based on MCM
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

pair<int, int> dp[101][101];

pair<int, int> solve(vector<int> &v, int i, int j)
{
    if (i >= j)
        return {v[i], 0};
    if (j - i == 1)
        return {(v[i] + v[j]) % 100, v[i] * v[j]};
    if (dp[i][j].first != -1 and dp[i][j].second != -1)
        return dp[i][j];

    int ans = INT_MAX, minVal;
    for (int k = i; k < j; k++)
    {
        auto left = solve(v, i, k), right = solve(v, k + 1, j);
        int tempAns = left.first * right.first;
        int tempVal = (left.first + right.first) % 100;
        if (tempAns + left.second + right.second < ans)
        {
            ans = tempAns + left.second + right.second;
            minVal = tempVal;
        }
    }
    return dp[i][j] = {minVal, ans};
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                dp[i][j] = {-1, -1};
        cout << solve(v, 0, n - 1).second << endl;
    }
    return 0;
}