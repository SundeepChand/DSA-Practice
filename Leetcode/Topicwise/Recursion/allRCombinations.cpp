#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<vector<int>> getNCR(vector<int> &v, int s, int n, int r)
{
    if (r == 0)
        return vector<vector<int>>(1, vector<int>());
    else if (s >= v.size())
        return vector<vector<int>>();

    vector<vector<int>> res;
    int prev = INT_MIN;
    for (int i = s; i <= v.size() - 1; i++)
    {
        if (v[i] == prev)
            continue;
        prev = v[i];
        vector<vector<int>> sub = getNCR(v, i + 1, n - 1, r - 1);
        for (auto &x : sub)
        {
            x.push_back(v[i]);
        }
        res.insert(res.end(), sub.begin(), sub.end());
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, r;
    cin >> n >> r;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<vector<int>> ans = getNCR(v, 0, n, r);
    for (auto x : ans)
    {
        reverse(x.begin(), x.end());
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}