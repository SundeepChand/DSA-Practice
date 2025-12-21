#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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
        int n, m;
        cin >> n >> m;
        vector<int> dist;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dist.push_back(max({i + j,
                                    n - i + m - j - 2,
                                    n - i - 1 + j,
                                    m - j - 1 + i}));
            }
        }
        sort(dist.begin(), dist.end());

        for (int x : dist)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}