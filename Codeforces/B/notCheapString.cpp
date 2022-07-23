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
        string s;
        cin >> s;

        int p;
        cin >> p;

        map<char, vector<int>> m;
        int curCost = 0;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]].push_back(i);
            curCost += (s[i] - 'a' + 1);
        }

        while (curCost > p)
        {
            curCost -= (m.rbegin()->first - 'a' + 1);
            int idx = m.rbegin()->second.back();
            s[idx] = '#';
            m.rbegin()->second.pop_back();
            if (m.rbegin()->second.size() == 0)
                m.erase(m.rbegin()->first);
        }
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '#')
                cout << s[i];
        cout << endl;
    }
    return 0;
}