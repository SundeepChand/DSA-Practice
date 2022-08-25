// https://codeforces.com/contest/670/problem/D1
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canMake(vector<int> &a, vector<int> &b, int k, int m)
{
    int g = 0;
    for (int i = 0; i < a.size() and g <= k; i++)
    {
        g += max(0LL, m * a[i] - b[i]);
    }
    return g <= k;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int lb = 0, ub = 1e10;
    int ans = 0;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (canMake(a, b, k, mid))
        {
            lb = mid + 1;
            ans = mid;
        }
        else
        {
            ub = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}