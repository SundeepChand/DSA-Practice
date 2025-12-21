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

        vector<int> v(10, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[x % 10]++;
        }

        bool poss = false;
        for (int i = 0; i < 10 and !poss; i++)
        {
            if (v[i] == 0)
                continue;
            v[i]--;
            for (int j = 0; j < 10 and !poss; j++)
            {
                if (v[j] == 0)
                    continue;
                v[j]--;
                for (int k = 0; k < 10 and !poss; k++)
                {
                    if (v[k] == 0)
                        continue;
                    if ((i + j + k) % 10 == 3)
                    {
                        poss = true;
                        break;
                    }
                }
                v[j]++;
            }
            v[i]++;
        }
        if (poss)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}