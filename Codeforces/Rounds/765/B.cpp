#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canSolve(vector<int> &v, int k)
{
    int n = v.size();
    for (int i = 0; i + (n - k) < n; i++)
        if (v[i] == v[i + n - k])
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
        int n;
        cin >> n;

        int ans = INT_MAX;
        vector<vector<int>> v(150001, vector<int>());
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[x].push_back(i);
        }

        for (int i = 0; i < 150001; i++)
        {
            for (int j = 1; j < v[i].size(); j++)
            {
                ans = min(ans, v[i][j] - v[i][j - 1]);
            }
        }
        if (ans == INT_MAX)
            cout << -1;
        else
            cout << (n - ans);
        cout << endl;
    }
    return 0;
}