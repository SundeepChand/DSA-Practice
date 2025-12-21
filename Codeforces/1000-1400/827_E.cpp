#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int solve(vector<int> &v, vector<int> &pref, int k)
{
    auto idx = upper_bound(v.begin(), v.end(), k) - v.begin();
    if (idx == 0)
        return 0;
    return pref[--idx];
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

        vector<int> v(n);
        vector<int> pref(n);
        int prevVal = 0, prevSum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[i] = max(prevVal, x);
            prevVal = v[i];
            pref[i] = prevSum + x;
            prevSum = pref[i];
        }

        // cerr << "v: ";
        // for (int x : v)
        //     cerr << x << " ";
        // cerr << endl;

        // cerr << "pref: ";
        // for (int x : pref)
        //     cerr << x << " ";
        // cerr << endl;

        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;

            cout << solve(v, pref, x) << " ";
        }
        cout << endl;
    }
    return 0;
}