#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canSolve(int lines, int k, int rem)
{
    int n = 0, v = 0;
    if (lines <= k)
    {
        n = (lines * (lines + 1)) / 2;
        v = lines;
    }
    else
    {
        n = k * k - (((2 * k - lines) * (2 * k - lines - 1)) / 2);
        v = 2 * k - lines;
    }
    if ((n - v + 1) <= rem)
        return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int k, x;
        cin >> k >> x;

        if (k * k <= x)
        {
            cout << (2 * k - 1) << endl;
            continue;
        }

        int mi = (x / (k * k)) * (2 * k - 1);
        int rem = x % (k * k);

        int lb = 0, ub = rem;
        int ans = 0;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (canSolve(mid, k, rem))
            {
                lb = mid + 1;
                ans = mid;
            }
            else
            {
                ub = mid - 1;
            }
        }
        cout << (mi + ans) << endl;
    }
    return 0;
}