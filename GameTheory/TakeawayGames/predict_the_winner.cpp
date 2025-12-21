#include <bits/stdc++.h>
using namespace std;

class SolutionDP {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& nums, int i, int j, bool t)
    {
        if (j < i)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (t == 0)
        {
            int a = nums[i] + solve(nums, i + 1, j, !t);
            int b = nums[j] + solve(nums, i, j - 1, !t);
            ans = max(a, b);
        }
        else
        {
            int a = solve(nums, i + 1, j, !t);
            int b = solve(nums, i, j - 1, !t);
            ans = min(a, b);
        }
            
        return (dp[i][j] = ans);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        
        int maxScore = solve(nums, 0, n - 1, 0);
        // cout<<maxScore<<endl;
        // Print the DP matrix
        for (auto x: dp)
        {
            for (auto y: x)
            {
                cout<<y<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
        return maxScore >= (sum - maxScore);
    }
};

int main()
{
    SolutionDP s;

    vector<int> v1 {1, 5, 2};
    vector<int> v2 {5, 2, 12, 6};
    cout<<s.PredictTheWinner(v2)<<endl;
    return 0;
}