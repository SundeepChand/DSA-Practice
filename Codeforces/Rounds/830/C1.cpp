#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

pair<int, int> getAns(vector<int> &v, vector<int> &s, vector<int> &x, int l)
{
    int n = s.size();
    int lb = l, ub = n - 1, r = n - 1;
    int ans = v[ub] + s[ub] - s[l] - (v[ub] ^ x[ub] ^ x[l]);
    // cerr << l << " " << r << " " << ans << endl;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        int ansMid = (v[mid] + s[mid] - s[l]) - (v[mid] ^ x[mid] ^ x[l]);
        // cerr << lb << " " << ub << " " << mid << " " << ansMid << endl;
        if (ansMid >= ans)
        {
            ub = mid - 1;
            r = mid;
            ans = ansMid;
        }
        else
            lb = mid + 1;
    }
    return {ans, r};
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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int l, r;
        cin >> l >> r;
        l--, r--;

        vector<int> s(n), x(n);
        s[0] = x[0] = 0;
        for (int i = 1; i < n; i++)
        {
            s[i] = (s[i - 1] + v[i - 1]);
            x[i] = (x[i - 1] ^ v[i - 1]);
        }

        // cerr << "S: ";
        // for (auto x : s)
        //     cerr << x << " ";
        // cerr << endl;
        // cerr << "X: ";
        // for (auto v : x)
        //     cerr << v << " ";
        // cerr << endl
        //      << endl;

        int ans = 0, ansL = -1, ansR = n + 1;
        for (int i = l; i <= r; i++)
        {
            pair<int, int> cur = getAns(v, s, x, i);
            if (cur.first > ans)
            {
                ans = cur.first, ansL = i, ansR = cur.second;
            }
            else if (cur.first == ans and ansR - ansL > cur.second - i)
            {
                ansL = i, ansR = cur.second;
            }
        }
        ansL++, ansR++;
        cout << ansL << " " << ansR << endl;
    }
    return 0;
}