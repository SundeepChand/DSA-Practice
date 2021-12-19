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

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n >= 130)
    {
        cout << "Yes" << endl;
    }
    else
    {
        unordered_set<int> u;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (u.find(v[i] ^ v[j] ^ v[k]) != u.end())
                    {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
            u.insert(v[i]);
        }
        cout << "No" << endl;
    }
    return 0;
}