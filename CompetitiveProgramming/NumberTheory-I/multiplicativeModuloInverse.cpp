#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> extendedEuclid(int a, int b)
{
    if (b == 0)
        return {1, 0};
    vector<int> res = extendedEuclid(b, a % b);
    return {res[1], res[0] - (a / b) * res[1]};
}

int computeMMI(int a, int m)
{
    if (__gcd(a, m) != 1)
        return -1;
    vector<int> res = extendedEuclid(a, m);
    return (res[0] % m + m) % m; // Trick to keep the ans in the range 1-(m - 1)
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, m;
    cin >> a >> m;

    int mmi = computeMMI(a, m);
    cout << mmi << endl;
    return 0;
}