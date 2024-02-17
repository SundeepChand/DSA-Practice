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

    int q;
    cin >> q;

    map<int, int> mp;

    set<int> s;

    while (q--)
    {
        char op;
        cin >> op;

        int n;
        cin >> n;

        if (op == '+')
        {
            s.insert(n);
        }
        else
        {
            int x = n;
            if (mp.find(n) != mp.end())
                x = mp[n];
            while (s.find(x) != s.end())
                x += n;
            cout << x << endl;

            mp[n] = x;
        }
    }
    return 0;
}