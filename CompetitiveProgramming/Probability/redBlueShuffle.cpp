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

        string a, b;
        cin >> a >> b;

        int gt = 0, lt = 0, eq = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
                gt++;
            else if (a[i] < b[i])
                lt++;
            else
                eq++;
        }
        if (gt > lt)
            cout << "RED";
        else if (gt < lt)
            cout << "BLUE";
        else
            cout << "EQUAL";
        cout << endl;
    }
    return 0;
}