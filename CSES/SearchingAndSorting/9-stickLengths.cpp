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
    sort(v.begin(), v.end());

    int ans = 0;
    int med = v[n / 2];
    for (int i = 0; i < n; i++)
    {
        ans += abs(v[i] - med);
    }
    cout << ans << endl;
    return 0;
}