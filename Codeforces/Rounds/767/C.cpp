#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int mex(unordered_set<int> &u)
{
    int m = 0;
    while (u.find(m) != u.end())
        m++;
    return m;
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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> post(n);
        bool seen[200001];
        memset(seen, 0, sizeof(seen));
        int cur_mex = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            seen[v[i]] = true;
            while (seen[cur_mex])
                cur_mex++;
            post[i] = cur_mex;
        }

        vector<int> ans;
        for (int i = 0; i < n;)
        {
            int m = -1, j = i;
            memset(seen, 0, sizeof(seen));
            cur_mex = 0;
            while (j < n && m != post[i])
            {
                seen[v[j]] = true;
                while (seen[cur_mex])
                    cur_mex++;
                m = cur_mex;
                j++;
            }
            ans.push_back(m);
            i = j;
        }

        cout << ans.size() << endl;
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}