#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int q;
    cin >> q;

    int k = 0;

    unordered_map<int, list<int>> u;
    while (q--)
    {
        int t, x, y;
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            u[x].push_back(k);
            k++;
        }
        else
        {
            cin >> x >> y;
            if (x != y)
            {
                u[y].splice(u[y].end(), u[x]);
                u.erase(x);
            }
        }
    }

    vector<int> ans(k);
    for (auto it = u.begin(); it != u.end(); it++)
    {
        for (auto x : it->second)
        {
            ans[x] = it->first;
        }
    }
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}