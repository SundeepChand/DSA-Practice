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
        int neg = 0, pos = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] < 0)
                neg++;
            if (v[i] > 0)
                pos++;
        }

        if (n % 2 == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<vector<int>> ans;
            for (int i = 0; i < n - 1; i++)
            {
                if (neg < pos and (v[i] == 1 and v[i + 1] == 1))
                {

                    ans.push_back({i + 1, i + 2});
                    pos--, neg++;
                    i++;
                }
                else if (neg > pos and (v[i] == -1 and v[i + 1] == -1))
                {
                    ans.push_back({i + 1, i + 2});
                    neg--;
                    pos++;
                    i++;
                }
                else
                    ans.push_back({i + 1, i + 1});
            }
            if (ans.back()[1] != n)
                ans.push_back({n, n});

            cout << ans.size() << endl;
            for (auto x : ans)
            {
                cout << x[0] << " " << x[1] << endl;
            }
        }
    }
    return 0;
}