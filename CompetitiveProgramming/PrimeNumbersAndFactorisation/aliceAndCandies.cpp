#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int solveBruteForce(int n)
{
    int ans = 0;
    int prev = 1, next = 1;
    int sum = 0;
    while (sum >= n || next <= n)
    {
        if (prev == next)
        {
            sum += next;
            next += 2;
            continue;
        }
        if (sum < n)
        {
            sum += next;
            next += 2;
        }
        else
        {
            if (sum == n)
            {
                // cout << prev << ", " << next << ", " << sum << endl;
                ans++;
            }
            sum -= prev;
            prev += 2;
        }
    }
    return ans;
}

int solveRootN(int n)
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0 && ((i + n / i) % 2 == 0))
            ans++;
    }
    return ans;
}

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
    cout << solveBruteForce(n) << endl;
    cout << solveRootN(n) << endl;
    return 0;
}