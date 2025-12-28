// https://leetcode.com/discuss/post/6244752/google-l3-interview-experience-questions-2utz/
#include <bits/stdc++.h>
using namespace std;

/*
I/P:
4
1
4
2
3 6
2
1 6
5
1 2 3 4 5

O/P:
4 4
6 6
7 7
8 8

*/

class Solution
{
    int dp[100000];

private:
    int getMaxScoreUtil(const vector<int> &arr, int i)
    {
        int n = arr.size();

        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        return max(arr[i] + getMaxScoreUtil(arr, i + arr[i]), getMaxScoreUtil(arr, i + 1));
    }

public:
    int getMaxScore(const vector<int> &arr)
    {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));

        return getMaxScoreUtil(arr, 0);
    }
};

class SolutionBottomUp
{
public:
    int getMaxScore(const vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp(n);

        dp[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1];
            if (i + arr[i] < n)
            {
                dp[i] = max(dp[i], arr[i] + dp[i + arr[i]]);
            }
        }
        return dp[0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    Solution s;
    SolutionBottomUp sbu;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << s.getMaxScore(arr) << " " << sbu.getMaxScore(arr) << endl;
    }
    return 0;
}