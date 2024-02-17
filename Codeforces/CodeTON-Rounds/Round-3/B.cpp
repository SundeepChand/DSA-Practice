#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

pair<int, int> getFreq(string &s)
{
    int x = 0, y = 0;
    for (char c : s)
    {
        x += (c == '0');
        y += (c == '1');
    }
    return {x, y};
}

int getMaxContiguous(string &s, char t)
{
    int n = s.size();
    int i = 0;

    int ans = 0;
    while (i < n)
    {
        int ctr = 0;
        while (i < n and s[i] == t)
            ctr++, i++;
        ans = max(ans, ctr);
        i++;
    }
    return ans;
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
        int n;
        cin >> n;

        string s;
        cin >> s;

        pair<int, int> ctr = getFreq(s);

        int x = getMaxContiguous(s, '0');
        int y = getMaxContiguous(s, '1');

        cout << max({ctr.first * ctr.second, x * x, y * y}) << endl;
    }
    return 0;
}