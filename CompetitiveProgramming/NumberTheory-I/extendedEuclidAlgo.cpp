#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> solve(int a, int b)
{
    // Solve for x, y such that ax + by = gcd(a, b)
    if (b == 0)
        return {1, 0, a};
    vector<int> res = solve(b, a % b);
    int gcd = res[2]; // GCD of a, b
    return {res[1], res[0] - (a / b) * res[1], res[2]};
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;

    vector<int> ans = solve(a, b);
    assert((a * ans[0] + b * ans[1]) == ans[2]);
    cout << a << " * " << ans[0] << " + " << b << " * " << ans[1] << " = " << ans[2] << endl;
    return 0;
}