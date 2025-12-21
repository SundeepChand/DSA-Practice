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

        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]] = i;
        }

        int i = 1, limit = -1, maxIdx = mp[v[0]];
        bool flag = false;
        set<int> st;
        while (i < n)
        {
            if (v[i] < v[i - 1] or i <= limit)
            {
                limit = max(limit, maxIdx);
            }
            maxIdx = max(maxIdx, mp[v[i]]);
            i++;
        }

        i = 0;
        while (i <= limit)
        {
            st.insert(v[i]);
            i++;
        }
        cout << st.size() << endl;
    }
    return 0;
}