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
        int n, q;
        cin >> n >> q;

        deque<pair<int, int>> qq;
        int maxS = -1, maxId = -1;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> v;
            cin >> v.first;
            v.second = i + 1;
            if (v.first > maxS)
            {
                maxS = v.first;
                maxId = i + 1;
            }
            qq.push_back(v);
        }

        vector<vector<int>> queries(q, vector<int>(3));
        for (int i = 0; i < q; i++)
        {
            int id, k;
            cin >> id >> k;
            queries[i][0] = k, queries[i][1] = i, queries[i][2] = id;
        }
        sort(queries.begin(), queries.end());

        vector<int> ans(q);

        map<int, int> mp;
        int m = 0;
        int i = 0;
        // cerr << "DEB: " << maxId << endl;
        while (qq.front().second != maxId)
        {
            auto a = qq.front();
            qq.pop_front();
            auto b = qq.front();
            qq.pop_front();
            // cerr << "DEB: " << a.second << " " << b.second << endl;
            if (a.first > b.first)
            {
                qq.push_front(a);
                mp[a.second]++;
                qq.push_back(b);
            }
            else
            {
                qq.push_front(b);
                mp[b.second]++;
                qq.push_back(a);
            }
            m++;
            while (i < q and m >= queries[i][0])
            {
                ans[queries[i][1]] = mp[queries[i][2]];
                i++;
            }
        }
        while (i < q)
        {
            if (queries[i][2] == maxId)
                ans[queries[i][1]] = mp[maxId] + (queries[i][0] - m);
            else
                ans[queries[i][1]] = mp[queries[i][2]];
            i++;
        }

        for (int x : ans)
        {
            cout << x << endl;
        }
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
        int n, q;
        cin >> n >> q;

        vector<int> strengths(n);
        deque<int> qq;
        int maxId = -1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == n)
            {
                maxId = i;
            }
            qq.push_back(i);
            strengths[i] = x;
        }

        vector<vector<int>> wins(n, vector<int>());
        int timer = 0;
        while (strengths[qq.front()] != n)
        {
            auto a = qq.front();
            qq.pop_front();
            auto b = qq.front();
            qq.pop_front();

            timer++;

            if (strengths[a] > strengths[b])
            {
                wins[a].push_back(timer);
                qq.push_front(a);
                qq.push_back(b);
            }
            else
            {
                wins[b].push_back(timer);
                qq.push_front(b);
                qq.push_back(a);
            }
        }

        for (int i = 0; i < q; i++)
        {
            int id, k;
            cin >> id >> k;

            id--;
            int ans;
            if (k <= timer)
            {
                ans = upper_bound(wins[id].begin(), wins[id].end(), k) - wins[id].begin();
            }
            else
            {
                if (id == maxId)
                    ans = k - timer + wins[id].size();
                else
                    ans = wins[id].size();
            }
            cout << ans << endl;
        }
    }
    return 0;
}