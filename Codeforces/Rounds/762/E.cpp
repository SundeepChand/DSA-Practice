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

        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }

        map<int, int> aux;
        vector<int> ans;
        int ct = 0;
        int mn = m.begin()->first;
        if (mn != 0)
        {
            ans.push_back(0);
        }
        else
        {
            for (int i = 0; i <= n; i++)
            {
                if (m[i] != 0)
                {
                    ans.push_back(m[i] + ct);
                    if (m[i] > 1)
                    {
                        aux[i] = m[i] - 1;
                        m[i] = 1;
                    }
                }
                else
                {
                    if (i == 0)
                    {
                        ans.push_back(0);
                    }
                    else if (m[i - 1] > 0)
                    {
                        ans.push_back(ct);
                        auto it = aux.rbegin();
                        // for (it = aux.rbegin(); it != aux.rend() && it->second < 1; it++)
                        //     ;
                        if (it == aux.rend())
                            break;
                        // cout << "DEB: " << i << ", " << it->first << ": " << it->second << endl;
                        m[i] = 1;
                        ct += (i - it->first);
                        (it->second)--;
                        if (it->second <= 0)
                            aux.erase(it->first);
                    }
                }
            }
        }
        // for (auto it = m.begin(); it != m.end(); it++)
        // {
        //     cout << it->first << ", " << it->second << endl;
        // }
        for (int i = 0; i <= n; i++)
        {
            if (i >= ans.size())
                cout << -1;
            else
                cout << ans[i];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}