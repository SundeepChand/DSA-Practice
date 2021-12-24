#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            // Check for overlap in intervals
            int m = ans.size();
            vector<int> last = ans[m - 1];
            if (intervals[i][0] <= last[1])
            {
                // They overlap
                ans[m - 1][1] = max(ans[m - 1][1], intervals[i][1]);
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};