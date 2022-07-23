#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void solve1()
{
    // Offline query processing
    int n, k;
    cin >> n >> k;

    vector<int> v;
    static unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        mp[v[i]] = i;
    }

    vector<vector<int>> q(k, vector<int>(3));
    for (int i = 0; i < k; i++)
    {
        cin >> q[i][0] >> q[i][1];
        q[i][2] = i;
    }

    sort(
        q.begin(),
        q.end(),
        [](vector<int> &a, vector<int> &b) -> bool
        {
            return mp[a[1]] < mp[b[1]];
        });

    vector<bool> res(k);

    set<int> st;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n and mp.find(q[i][1]) != mp.end() and j <= mp[q[i][1]])
        {
            st.insert(v[j]);
            j++;
        }
        // cout << q[i][0] << " " << q[i][1] << " " << q[i][2] << endl;
        if (st.find(q[i][1]) != st.end() and st.find(q[i][0]) != st.end())
            res[q[i][2]] = 1;
        else
            res[q[i][2]] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        if (res[i])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}

void solve2()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (mp.find(v[i]) == mp.end())
            mp[v[i]] = {i, i};
        mp[v[i]].first = min(mp[v[i]].first, i);
        mp[v[i]].second = max(mp[v[i]].second, i);
    }

    vector<bool> ans(k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        if (mp.find(a) != mp.end() and mp.find(b) != mp.end() and mp[a].first < mp[b].second)
            ans[i] = true;
        else
            ans[i] = false;
    }
    for (auto x : ans)
    {
        if (x)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
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
        solve2();
    }
    return 0;
}