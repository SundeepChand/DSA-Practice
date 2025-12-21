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

    int n = 100;

    vector<int> primes;
    vector<bool> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!sieve[i])
            continue;
        primes.push_back(i);
        for (int j = i * i; j <= n; j += i)
        {
            sieve[j] = 0;
        }
    }

    cout << "Prime numbers <= " << n << endl;
    for (auto x : primes)
        cout << x << " ";
    cout << endl;
    return 0;
}