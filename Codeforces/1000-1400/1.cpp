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
        int n;
        cin >> n;

        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({b - a, a, b});
        }
        sort(v.begin(), v.end());

        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(i);

        for (int i = 0; i < n; i++)
        {
            auto lb = s.lower_bound(v[i][1]);
            cout << v[i][1] << " " << v[i][2] << " " << (*lb) << endl;
            s.erase(lb);
        }
    }
    return 0;
}