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

    int N = 1e9;
    int SQRT_N = sqrt(N);
    vector<int> primes;

    vector<bool> sieve(SQRT_N + 2, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (!sieve[i])
            continue;
        primes.push_back(i);
        for (int j = i * i; j < sieve.size(); j += i)
        {
            sieve[j] = false;
        }
    }

    // for (int x : primes)
    // {
    //     cerr << x << " ";
    // }
    // cerr << endl;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> m >> n;

        vector<bool> sieve2(n - m + 1, true);
        if (m == 1)
            sieve2[0] = false;
        for (int p : primes)
        {
            int start_idx = max(int(ceil(double(m) / p) * p), 2 * p);
            for (int j = start_idx; j <= n; j += p)
            {
                if (j < sieve.size())
                    sieve2[j - m] = sieve[j];
                else
                    sieve2[j - m] = false;
            }
        }

        for (int i = 0; i < sieve2.size(); i++)
        {
            if (sieve2[i])
                cout << (i + m) << endl;
        }
        cout << endl;
    }
    return 0;
}