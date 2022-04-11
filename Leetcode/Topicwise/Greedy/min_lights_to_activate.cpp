#include <bits/stdc++.h>
using namespace std;

// Algo 1
// Greedy
int minLightsGreedy(const vector<int> &A, int cur, int lightPos, const int &B)
{
    int n = A.size();

    if (lightPos >= n - 1)
        return 0;

    int ans = INT_MAX - 10000;
    int maxRight = -1;
    for (int i = cur; i < n and i <= lightPos + B; i++)
        if (A[i])
            maxRight = max(maxRight, i);
    if (maxRight != -1)
        ans = 1 + minLightsGreedy(A, maxRight + 1, max(lightPos, maxRight + B - 1), B);

    return ans;
}

int solveGreedy(vector<int> &A, int B)
{
    int ans = minLightsGreedy(A, 0, -1, B);
    return ans >= INT_MAX - 10000 ? -1 : ans;
}

// Algo 2
// DP - WIP (currently giving WA)
int minLights(const vector<int> &A, int cur, int lightPos, const int &B, int dp[1011][1011])
{
    int n = A.size();

    // if (cur == 3)
    //     cout<<"DEB: "<<cur<<" "<<lightPos<<", ";

    if (lightPos >= n - 1)
        return 0;

    if (dp[cur][lightPos] != -1)
        return dp[cur][lightPos];

    int ans = INT_MAX - 10000;
    // int maxRight = -1;
    for (int i = cur; i < n and i <= lightPos + B; i++)
        if (A[i])
            ans = min(ans, 1 + minLights(A, i + 1, max(lightPos, i + B - 1), B, dp));
    // maxRight = max(maxRight, i);
    // if (maxRight != -1)
    //     ans = 1 + minLights(A, maxRight + 1, max(lightPos, maxRight + B - 1), B);

    return dp[cur][lightPos] = ans;
}

int solve(vector<int> &A, int B)
{
    int dp[1011][1011];
    memset(dp, -1, sizeof(dp));
    int ans = minLights(A, 0, -1, B, dp);
    return ans >= INT_MAX - 10000 ? -1 : ans;
}

int main()
{
    return 0;
}