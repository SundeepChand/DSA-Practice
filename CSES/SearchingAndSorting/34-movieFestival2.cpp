#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());

    multiset<int> m;
    for (int i = 0; i < k; i++)
    {
        m.insert(0);
    }

    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = m.lower_bound(v[i].second);
        if (it != m.end() && *it <= v[i].second)
        {
            ctr++;
            m.erase(it);
            m.insert(v[i].first);
        }
        else if (it != m.begin())
        {
            it--;
            ctr++;
            m.erase(it);
            m.insert(v[i].first);
        }
    }
    cout << ctr << endl;

    return 0;
}