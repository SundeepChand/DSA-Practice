#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i, e = points[i][1];
            while (j < n && points[j][0] <= e)
                j++;
            ans++;
            i = j - 1;
        }
        return ans;
    }
};