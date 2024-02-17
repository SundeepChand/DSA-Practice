#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canMove(int n, int x, int y, set<int> s1, set<int> s2)
{
    for (int i = 1; i <= n; i++)
    {
        if (s2.find(i) == s2.end())
            return true;
        if (s1.find(i) == s1.end())
            return true;
    }
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
        int n, m;
        cin >> n >> m;

        set<int> r, c;
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            r.insert(x);
            c.insert(y);

            v.push_back({x, y});
        }

        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            if (canMove(n, v[i].first, v[i].second, r, c))
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}