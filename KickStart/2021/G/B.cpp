#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef unsigned long long ull;

int d(vector<pair<pair<int, int>, pair<int, int>>> v, int x, int y)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if ((x >= v[i].first.first && x <= v[i].second.first) && (y >= v[i].first.second && y <= v[i].second.second))
        {
            ans += 0;
        }
        else if (x >= v[i].first.first && x <= v[i].second.first)
        {
            ans += min(abs(v[i].second.first - y), abs(v[i].second.second - y));
        }
        else if (y >= v[i].first.second && y <= v[i].second.second)
        {
            ans += min(abs(v[i].first.first - x), abs(v[i].second.first - x));
        }
        else
            ans += (min(abs(v[i].first.first - x), abs(v[i].second.first - x)) + min(abs(v[i].second.first - y), abs(v[i].second.second - y)));
    }
    return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    int temp = t;

    while (t--)
    {
        int k;
        cin >> k;

        vector<pair<pair<int, int>, pair<int, int>>> v(k);
        for (int i = 0; i < k; i++)
        {
            cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
        }

        int ans = INT_MAX;
        int x = 0, y = 0;
        for (int i = -1000; i <= 1000; i++)
        {
            for (int j = -1000; j <= 1000; j++)
            {
                int dist = d(v, i, j);
                if (dist < ans)
                {
                    x = i;
                    y = j;
                    ans = dist;
                }
            }
        }

        cout << "Case #" << (temp - t) << ": " << x << " " << y << endl;
    }
    return 0;
}