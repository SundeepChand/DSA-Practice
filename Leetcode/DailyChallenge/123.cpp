#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> val(n);
        val[n - 1] = 0;
        int post = max(0, prices[n - 1]);
        for (int i = n - 2; i >= 0; i--)
            val[i] = max(val[i + 1], post - prices[i]), post = max(post, prices[i]);

        int ans = max(0, val[0]), pre = prices[0];
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, prices[i] - pre + val[i]);
            pre = min(pre, prices[i]);
        }

        return ans;
    }
};