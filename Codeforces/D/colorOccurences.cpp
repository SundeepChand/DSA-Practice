#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<vector<int>> solve(string &st, vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    int n = intervals.size(), m = st.size(), curStart = 0;
    for (int i = 0; i < n and curStart < m; i++)
    {
        int j = i, maxEndIdx = i - 1, maxEnd = curStart - 1;
        while (j < n and intervals[j][0] <= curStart)
        {
            // cout << j << " " << maxEnd << " " << curStart << endl;
            if (intervals[j][1] > maxEnd)
            {
                maxEnd = intervals[j][1];
                maxEndIdx = j;
            }
            j++;
        }
        if (j == i)
            return vector<vector<int>>();
        i = j - 1;
        curStart = maxEnd + 1;
        ans.push_back(intervals[maxEndIdx]);
    }
    return (curStart < m) ? vector<vector<int>>() : ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int q;
    cin >> q;

    while (q--)
    {
        string t;
        cin >> t;

        int n;
        cin >> n;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        map<pair<int, int>, int> intv;
        for (int j = 0; j < n; j++)
        {
            string s = v[j];
            int n = s.size(), m = t.size();
            for (int i = 0; i < m - n + 1; i++)
            {
                if (t.substr(i, n) == s)
                    intv[{i, i + n - 1}] = j;
            }
        }
        vector<vector<int>> intervals;
        for (auto x : intv)
        {
            intervals.push_back({x.first.first, x.first.second, x.second});
        }

        // for (auto x : intervals)
        //     cout << x[0] << " " << x[1] << " " << x[2] << endl;

        vector<vector<int>> ans = solve(t, intervals);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            cout << ans.size() << endl;
            for (auto x : ans)
                cout << x[2] + 1 << " " << x[0] + 1 << endl;
        }
    }

    return 0;
}