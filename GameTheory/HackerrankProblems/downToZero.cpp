// https://www.hackerrank.com/challenges/down-to-zero-ii/problem
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int dp[N + 1];

int main()
{
    // Precompute dp
    // The precomputation step is important here. In the naive way it can be done in O(n ^ (3/2)) time
    // But this does not work for the given input size, i.e 10^6.
    // So we need to use a O(n * log n) approach to precompute
    // For this, we take a & b as parameters, and try to minimise the value of a * b
    for (int i = 0; i <= N; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int a = 2; a <= N; a++)
    {
        if (dp[a] == INT_MAX || dp[a - 1] + 1 < dp[a])
            dp[a] = 1 + dp[a - 1];
        for (int b = 2; b <= a && a * b <= N; b++)
        {

            if (dp[a] + 1 < dp[a * b])
                dp[a * b] = dp[a] + 1;
        }
    }

    // for (int i = 0; i < 20; i++)
    // {
    //     cout << i << ": " << dp[i] << endl;
    // }

    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        cout << dp[n] << endl;
    }
    return 0;
}