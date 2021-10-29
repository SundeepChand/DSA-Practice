#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;

        v[i] = ceil(x / m);
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= v[ans - 1])
            ans = i + 1;
    }
    cout << ans << endl;
    return 0;
}