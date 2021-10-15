#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n, x;
    cin >> n >> x;

    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            ll key = x - (v[i].first + v[j].first);
            auto el = lower_bound(v.begin() + j + 1, v.end(), make_pair(key, INT_MIN));
            if (el != v.end() && el->first == key)
            {
                cout << v[i].second << " " << v[j].second << " " << el->second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}