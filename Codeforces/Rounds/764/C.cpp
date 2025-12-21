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

        vector<int> v(n);
        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            while (v[i] > n)
                v[i] /= 2;
            s.insert(v[i]);
        }
        bool flag = true;
        for (int i = n; i > 0; i--)
        {
            int er = -1;
            for (auto it = s.rbegin(); it != s.rend(); it++)
            {
                int j = *it;
                while (j > i)
                    j /= 2;
                if (j == i)
                {
                    er = *it;
                    break;
                }
            }
            if (er == -1)
            {
                flag = false;
                break;
            }
            s.erase(s.find(er));
        }

        if (!flag)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
    return 0;
}