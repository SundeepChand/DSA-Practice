// Solution: Minimum number of rooms required is equal
// to the largest number of overlapping intervals.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<int, int>> v1;
    map<pair<int, int>, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v1.push_back({a, b});
        m[{a, b}].push_back(i);
    }
    sort(v1.begin(), v1.end());

    set<int> rooms;
    for (int i = 1; i <= 200000; i++)
        rooms.insert(i);
    multiset<pair<int, int>> s;
    vector<int> alloc(n);
    int ans = 1, prev = 1;
    for (int i = 0; i < n; i++)
    {
        int room = -1;
        while (s.size() > 0 && v1[i].first > s.begin()->first)
        {
            rooms.insert(s.begin()->second);
            s.erase(s.begin());
        }
        room = *rooms.begin();
        rooms.erase(rooms.begin());

        alloc[*m[v1[i]].rbegin()] = room;
        m[v1[i]].pop_back();

        s.insert({v1[i].second, room});

        ans = max(ans, room);
    }

    cout << ans << endl;
    for (int x : alloc)
        cout << x << " ";
    return 0;
}