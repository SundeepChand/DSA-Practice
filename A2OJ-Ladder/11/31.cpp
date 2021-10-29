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

    int n;
    cin >> n;

    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    // k - 1 % n == 0
    int ans = 0;
    for (int i = 1; i <= 5; i++)
    {
        if ((sum + i - 1) % (n + 1) != 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}