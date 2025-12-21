#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

char getCharAtPos(string &s, vector<pair<int, int>> &v, int pos)
{
    auto idx = upper_bound(v.begin(), v.end(), make_pair(pos, LONG_LONG_MAX), cmp) - v.begin();

    idx--;
    int diff = v[idx].second;
    if (diff == 0)
    {
        return s[pos];
    }
    return getCharAtPos(s, v, pos - diff);
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
        int n, c, q;
        cin >> n >> c >> q;

        string s;
        cin >> s;

        vector<pair<int, int>> vp;
        vp.push_back({0, 0});
        vp.push_back({n - 1, 0});

        int end = n - 1;

        for (int i = 0; i < c; i++)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;

            vp.push_back({end + 1, end + 1 - l});
            vp.push_back({end + 1 + r - l, end + 1 - l});
            end = end + 1 + r - l;
        }

        for (int i = 0; i < q; i++)
        {
            int k;
            cin >> k;
            k--;
            cout << getCharAtPos(s, vp, k) << endl;
        }
    }
    return 0;
}