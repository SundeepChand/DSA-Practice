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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        bool poss = true;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n and v[j] == v[i])
                j++;
            j--;
            if (i == j)
            {
                poss = false;
                break;
            }
            ans.push_back(j + 1);
            while (i < j)
            {
                ans.push_back(i + 1);
                i++;
            }
        }
        if (!poss)
            cout << -1 << endl;
        else
        {
            for (int x : ans)
                cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}