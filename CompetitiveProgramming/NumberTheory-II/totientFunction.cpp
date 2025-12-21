#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> primes;
void sieve()
{
    int N = 1e5 + 1;
    vector<bool> isprime(N, true);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
}

int totient(int n)
{
    int ans = n;
    for (int i = 0; i < primes.size() && primes[i] * 2 <= n; i++)
    {
        if (n % primes[i] == 0)
            ans = (ans / primes[i]) * (primes[i] - 1);
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

    sieve();
    cout << totient(10) << endl;
    return 0;
}