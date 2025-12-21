#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool isPossible(vector<int> &v, int k, int c)
{
    int n = v.size();
    int prev = v[0];
    c--;
    for (int i = 1; i < n; i++)
    {
        if (v[i] - prev >= k)
            prev = v[i], c--;
    }
    return c <= 0;
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
        int n, c;
        cin >> n >> c;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int lb = 0, ub = 1e9, ans = 0;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (isPossible(v, mid, c))
                lb = mid + 1, ans = mid;
            else
                ub = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}