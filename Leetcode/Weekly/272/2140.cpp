#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    
    ll dp[100001];
    
    ll solve(vector<vector<int>> &q, int i)
    {
        int n = q.size();
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        ll ans = solve(q, i + 1);
        ans = max(ans, q[i][0] + solve(q, i + q[i][1] + 1));
        return dp[i] = ans;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        memset(dp, -1, sizeof(dp));
        return solve(questions, 0);
    }
};