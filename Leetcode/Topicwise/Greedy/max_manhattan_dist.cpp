#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int manhattan(pair<int, int> &p1, pair<int, int> &p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<pair<int, int>> points(4); // 0 - xmin, 1 - ymin, 2 - xmax, 3 - ymax
    points[0].first = points[1].second = INT_MAX;
    points[2].first = points[3].second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (v[i].first < points[0].first)
            points[0] = v[i];
        if (v[i].first > points[2].first)
            points[2] = v[i];
        if (v[i].second < points[1].second)
            points[1] = v[i];
        if (v[i].second > points[3].second)
            points[3] = v[i];
    }

    pair<int, int> p1, p2;
    int max_dist = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int cur_dist = manhattan(points[i], points[j]);
            if (cur_dist > max_dist)
                max_dist = cur_dist, p1 = points[i], p2 = points[j];
        }
    }
    cout << "(" << p1.first << ", " << p1.second << ") (" << p2.first << ", " << p2.second << ")" << endl;

    return 0;
}