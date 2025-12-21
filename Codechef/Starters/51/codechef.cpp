#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void solve1()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ctr = 0;
        while (n)
        {
            n = n & (n - 1);
            ctr++;
        }
        cout << (ctr - 1) << endl;
    }
}

void solve2()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int j = n, k = 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << j;
                j--;
            }
            else
            {
                cout << k;
                k++;
            }
            cout << " ";
        }
        cout << endl;
    }
}

void solve3()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int t = 0;
        for (char c : s)
        {
            if (c == '1')
                t++;
        }

        if (t == 0)
        {
            cout << (n * m);
        }
        else
        {
            int ans = 0, x = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                    x++;
                double val = ((double)(m) / 2.0) - ((double)(x) / t);
                if (val == ceil(val))
                    ans++;
            }
            cout << ans;
        }
        cout << endl;
    }
}

void solve4()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int dp[100001][2];

        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i][1] = 0;
            dp[i][0] = max({dp[i][0],
                            (v[i] ^ v[i - 1]) + dp[i - 1][0],
                            (v[i] ^ (v[i - 1] + x)) + dp[i - 1][1]});

            dp[i][1] = max({dp[i][1],
                            ((v[i] + x) ^ v[i - 1]) + dp[i - 1][0],
                            ((v[i] + x) ^ (v[i - 1] + x)) + dp[i - 1][1]});
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2 == 1)
                xr = xr ^ (n - 1 - i);
        }

        if (xr == 0)
            cout << "Cook";
        else
            cout << "Chef";
        cout << endl;
    }
    return 0;
}