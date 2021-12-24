#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSolve(vector<int> &w, int minWeight, int days)
    {
        int curWeight = 0;
        int curDays = 1;
        for (int i = 0; i < w.size(); i++)
        {
            if (curWeight + w[i] <= minWeight)
                curWeight += w[i];
            else
            {
                curWeight = w[i];
                curDays++;
            }
        }
        return (curDays <= days);
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int lb = 0, ub = 0;
        for (int w : weights)
        {
            lb = max(lb, w);
            ub += w;
        }

        int ans = ub;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (canSolve(weights, mid, days))
            {
                ans = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        return ans;
    }
};