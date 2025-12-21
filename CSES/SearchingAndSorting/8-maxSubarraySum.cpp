#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = v[0], sub = 0;
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
        if (v[i - 1] < sub)
            sub = v[i - 1];
        if (v[i] - sub > ans)
            ans = v[i] - sub;
    }
    cout << ans << endl;
    return 0;
}