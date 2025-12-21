#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());

    /*
    // This if else part ultimately reduces to the statement
    // max(sum, 2 * v[n - 1]);
    if ((sum - v[n - 1]) < v[n - 1])
    {
        cout << (2 * v[n - 1]) << endl;
    }
    else
    {
        cout << sum << endl;
    }
    */
    cout << max(sum, 2 * v[n - 1]) << endl;
    return 0;
}