#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

// int dp[100001][100001];
int solveRecursive(int a, int b)
{
    if (b < a)
        return 0;
    if (a == 0)
        return 1;
    if (a == b)
        return solveRecursive(a - 1, b);
    return (solveRecursive(a - 1, b) + solveRecursive(a, b - 1)) % MOD;
}

int solve(int a, int b)
{
    vector<int> prev = {1};
    for (int j = 1; j <= b; j++)
    {
        vector<int> cur = {1};
        for (int i = 1; i < j; i++)
            cur.push_back((cur[i - 1] + prev[i]) % MOD);
        cur.push_back(*cur.rbegin());
        prev = cur;
    }
    return prev[b];
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
    cin >> n;

    string s;
    cin >> s;

    if (n % 2 == 1)
        cout << 0 << endl;
    else
    {
        int a = n / 2, b = n / 2;
        for (auto x : s)
        {
            if (x == '(')
                a--;
            else
                b--;
            if (a > b || a < 0 || b < 0)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        // memset(dp, -1, sizeof(dp));
        cout << solve(a, b) << endl;
    }
    return 0;
}