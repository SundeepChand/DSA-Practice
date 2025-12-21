#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// #define int long long

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first == b.first)
    {
        return (a.second.first - a.second.second) < (b.second.first - b.second.second);
    }
    return (a.first < b.first);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int temp = t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int ans = INT_MAX;

        vector<int> v(n);
        vector<pair<int, int>> m;
        cin >> v[0];
        if (v[0] == k)
        {
            ans = 1;
        }
        m.push_back({v[0], 0});

        vector<pair<int, pair<int, int>>> m2;
        for (int i = 1; i < n; i++)
        {
            cin >> v[i];

            v[i] += v[i - 1];
            if (v[i] == k)
            {
                ans = min(ans, i + 1);
            }
            m.push_back({v[i], i});
        }

        for (int i = 0; i < n; i++)
        {
            if (m[i].first <= k)
                m2.push_back({m[i].first, {m[i].second, 0}});

            int j = i + 1;
            for (; j < n; j++)
            {
                int x = m[j].first - m[i].first;
                if (x <= k)
                    m2.push_back({x, {m[j].second, m[i].second + 1}});
            }
        }

        sort(m2.begin(), m2.end(), cmp);

        for (auto i = m2.begin(); i != m2.end(); i++)
        {
            if (i->first == k)
            {
                ans = min(ans, (i->second).first - (i->second).second + 1);
            }
            int x = k - i->first;
            vector<pair<int, pair<int, int>>>::iterator temp;
            if (x > i->first)
                temp = lower_bound(i + 1, m2.end(), make_pair(k - i->first, make_pair(-1, -1)), cmp);
            else
                temp = lower_bound(m2.begin(), i - 1, make_pair(k - i->first, make_pair(-1, -1)), cmp);
            if (temp != m2.end() && temp->first + i->first == k)
            {
                while (temp->first + i->first == k)
                {
                    if (temp != i && ((i->second).first < (temp->second).second || (temp->second).first < (i->second).second))
                    {
                        ans = min(ans, (i->second).first - (i->second).second + (temp->second).first - (temp->second).second + 2);
                        break;
                    }
                    temp++;
                }
            }
        }

        if (ans == INT_MAX)
            ans = -1;
        cout << "Case #" << (temp - t) << ": " << ans << endl;
    }
    return 0;
}