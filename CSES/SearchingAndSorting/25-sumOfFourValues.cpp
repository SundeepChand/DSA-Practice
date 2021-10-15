#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool allDistinct(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second)
        return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());
    set<pair<ll, pair<ll, ll>>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll key = x - (v[i].first + v[j].first);
            auto it = s.lower_bound({key, {0, 0}});
            if (it != s.end() && it->first == key)
            {
                auto next = it;
                next++;
                while (next != s.end() && !allDistinct(it->second, {v[i].second, v[j].second}) && next->first == key)
                {
                    it++;
                    next++;
                }
                if (allDistinct(it->second, {v[i].second, v[j].second}))
                {
                    // Found the elements
                    cout << (it->second).first << " " << (it->second).second << " " << v[i].second << " " << v[j].second << endl;
                    return 0;
                }
            }
            s.insert({v[i].first + v[j].first, {v[i].second, v[j].second}});
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}