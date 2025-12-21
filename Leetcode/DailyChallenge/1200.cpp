#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int diff = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] < diff)
                diff = arr[i] - arr[i - 1];
        }

        vector<vector<int>> ans;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] == diff)
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};