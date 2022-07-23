#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
// #define int ll

// vector<vector<vector<int>>> dp;

// int solve(vector<int> &a, int i, vector<int> &b, int j, bool pickA)
// {
//     int n = a.size(), m = b.size();
//     if (pickA and i >= n)
//         return 0;
//     if (!pickA and j >= m)
//         return 0;
//     if (dp[i][j][pickA] != -1)
//         return dp[i][j][pickA];

//     if (pickA)
//     {
//         int ans = a[i] + solve(a, i + 1, b, j, pickA);
//         auto idx = lower_bound(b.begin() + j, b.end(), a[i]) - b.begin();
//         if (idx < m and b[idx] == a[i])
//             ans = max(ans, a[i] + solve(a, i + 1, b, idx + 1, !pickA));
//         return dp[i][j][pickA] = ans;
//     }
//     int ans = b[j] + solve(a, i, b, j + 1, pickA);
//     auto idx = lower_bound(a.begin() + i, a.end(), b[j]) - a.begin();
//     if (idx < n and a[idx] == b[j])
//         ans = max(ans, b[j] + solve(a, idx + 1, b, j + 1, !pickA));
//     return dp[i][j][pickA] = ans;
// }

int solve(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = 0, j = 0, sumA = 0, sumB = 0, ans = 0;
    while (i < n or j < m)
    {
        if (i >= n)
        {
            sumB += b[j];
            j++;
        }
        else if (j >= m)
        {
            sumA += a[i];
            i++;
        }
        else if (a[i] < b[j])
        {
            sumA += a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            sumB += b[j];
            j++;
        }
        else
        {
            ans += max(sumA, sumB);
            sumA = sumB = 0;
            ans += a[i];
            i++, j++;
        }
    }
    ans += max(sumA, sumB);

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (true)
    {
        int n, m;
        cin >> n;
        if (n == 0)
            break;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];

        cout << solve(a, n, b, m) << endl;
    }
    return 0;
}