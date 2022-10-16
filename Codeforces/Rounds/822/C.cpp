#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

const int N = 1000001;
bool sieve[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(sieve, 0, sizeof(sieve));
    // sieve[0] = 0;
    // sieve[1] = 1;
    // for (int i = 2; i < N; i++)
    // {
    //     if (sieve[i] != -1)
    //         continue;
    //     sieve[i] = i;
    //     for (int j = i * i; j < N; j += i)
    //     {
    //         if (sieve[j] == -1)
    //             sieve[j] = i;
    //     }
    // }
    // for (int i = 1; i < 16; i++)
    //     cerr << sieve[i] << " ";
    // cerr << endl;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string t;
        cin >> t;

        vector<bool> v(n, false);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                if (t[j - 1] == '1')
                    break;
                else if (v[j - 1] == 1)
                    continue;

                ans += i;
                v[j - 1] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}