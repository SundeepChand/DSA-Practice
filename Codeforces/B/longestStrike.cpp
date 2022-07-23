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
        int n, k;
        cin >> n >> k;

        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }

        vector<pair<int, int>> v;
        for (auto x : m)
        {
            v.push_back(x);
        }

        int sz = v.size();
        int i = 0, j = 0;
        int l = -1, r = -1;
        while (j < sz)
        {
            if (v[j].second < k)
            {
                i = ++j;
                continue;
            }
            int prev = v[i].first;
            while (j < sz && v[j].first <= prev + 1 && v[j].second >= k)
            {
                prev = v[j].first;
                j++;
            }
            if (r - l <= v[j - 1].first - v[i].first)
                l = v[i].first, r = v[j - 1].first;
            i = j;
        }
        if (l == -1)
            cout << -1;
        else
            cout << l << " " << r;
        cout << endl;
    }
    return 0;
}