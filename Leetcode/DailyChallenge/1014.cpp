#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int m = values[0] - 1, n = values.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, m + values[i]);
            m = max(m - 1, values[i] - 1);
        }
        return ans;
    }
};