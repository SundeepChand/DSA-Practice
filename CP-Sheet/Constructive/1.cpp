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

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        string cur;
        cin >> cur;

        if (cur[1] == '+')
            x++;
        else
            x--;
    }
    cout << x << endl;

    return 0;
}