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
        int n;
        cin >> n;

        set<int> st1, st2;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a == b)
            {
                flag = false;
                continue;
            }

            if (st1.find(a) == st1.end() and st1.find(b) == st1.end())
            {
                st1.insert(a);
                st1.insert(b);
            }
            else if (st2.find(a) == st2.end() and st2.find(b) == st2.end())
            {
                st2.insert(a);
                st2.insert(b);
            }
            else
            {
                flag = false;
            }
        }

        if (flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}