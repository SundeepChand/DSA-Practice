#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int32_t main()
{
    /*

    l o g i c
    1 2 3 4 5

    l -> c = 9

    l -> i = 3
    i -> g = 2
    g -> c = 4

    */
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
        int n;
        string s;
        cin >> s;

        n = s.length();

        map<char, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]].push_back(i + 1);
        }

        vector<int> path;
        int cost = abs(s[n - 1] - s[0]);

        char lb = s[0], ub = s[n - 1];
        bool flag = false;
        if (lb > ub)
        {
            flag = true;
            swap(lb, ub);
        }

        for (char c = lb; c <= ub; c++)
        {
            if (flag)
                reverse(mp[c].begin(), mp[c].end());
            for (auto x : mp[c])
            {
                path.push_back(x);
            }
        }
        if (flag)
            reverse(path.begin(), path.end());

        cout << cost << " " << path.size() << endl;
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}