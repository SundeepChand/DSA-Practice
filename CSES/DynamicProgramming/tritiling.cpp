#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int dp[35][8];

int solve(const int &n, int i, int t1, int t2, int t3)
{
    if ((i == n) && t1 && t2 && t3)
    {
        return 1;
    }
    if (i > n)
        return 0;

    int state = t1 | (t2 << 1) | (t3 << 2);
    int t4, t5, t6;
    t4 = t5 = t6 = (i + 1 < n);
    int nextState = t4 | (t5 << 1) | (t6 << 2);

    if (dp[i][state] != -1)
        return dp[i][state];

    int count = 0;
    if (state == 3) // state = 011
    {
        count += solve(n, i + 1, true, true, true);
        count += solve(n, i + 1, true, false, false);
    }
    if (state == 6) // state = 110
    {
        count += solve(n, i + 1, true, true, true);
        count += solve(n, i + 1, false, false, true);
    }
    if (state == 0) // state = 000
    {
        count += solve(n, i + 1, true, true, true);
    }
    if (state == 7) // state = 111
    {
        count += solve(n, i + 1, false, true, true);
        count += solve(n, i + 1, true, true, false);
        count += solve(n, i + 1, false, false, false);
    }
    if (state == 1) // state = 001
    {
        count += solve(n, i + 1, false, true, true);
    }
    if (state == 2) // state = 010
    {
        count += solve(n, i + 1, true, false, true);
    }
    if (state == 4) // state = 100
    {
        count += solve(n, i + 1, true, true, false);
    }
    if (state == 5) // state = 101
    {
        count += solve(n, i + 1, true, false, true);
    }
    return dp[i][state] = count;
}

int countWays(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(n, 0, 1, 1, 1);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif

    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
        {
            break;
        }

        cout << countWays(n) << endl;
    }
    return 0;
}