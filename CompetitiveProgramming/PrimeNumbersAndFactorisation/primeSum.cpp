#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int solve(int n)
{
    n++;
    vector<bool> sieve(n, 1);
    sieve[0] = sieve[1] = 0;

    vector<int> primes;
    for (int i = 2; i < n; i++)
    {
        if (!sieve[i])
            continue;
        primes.push_back(i);
        for (int j = i * i; j < n; j += i)
        {
            sieve[j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i; j < primes.size(); j++)
        {
            int sum = primes[i] + primes[j];
            if (sum < n && sieve[sum])
                ans++;
        }
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

    cout << solve(n) << endl;
    return 0;
}