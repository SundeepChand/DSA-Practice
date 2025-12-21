#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

bool canPlace(vector<int> v1, vector<int> v2, int rot)
{
    if (rot == 0 && v1[0] < v2[0] && v1[1] < v2[1] && v1[2] < v2[2])
        return true;
    if (rot == 1 && v1[0] < v2[0] && v1[1] < v2[2] && v1[2] < v2[1])
        return true;
    if (rot == 2 && v1[0] < v2[1] && v1[1] < v2[0] && v1[2] < v2[2])
        return true;
    if (rot == 3 && v1[0] < v2[2] && v1[1] < v2[1] && v1[2] < v2[0])
        return true;
    return false;
}

int findMaxDepth(vector<vector<int>> v)
{
    sort(v.begin(), v.end(), comparator);

    int n = v.size();
    vector<int> dp(n);
    dp[0] = v[0][2];
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        int temp = v[i][2];
        for (int j = 0; j < i; j++)
        {
            if (canPlace(v[j], v[i], 0))
                temp = max(temp, dp[j] + v[i][2]);
            if (canPlace(v[j], v[i], 1))
                temp = max(temp, dp[j] + v[i][1]);
            if (canPlace(v[j], v[i], 2))
                temp = max(temp, dp[j] + v[i][2]);
            if (canPlace(v[j], v[i], 3))
                temp = max(temp, dp[j] + v[i][0]);
        }
        dp[i] = temp;
        ans = max(ans, temp);
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {
        {2, 2, 8},
        {2, 1, 2},
        {3, 2, 3},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5}
    };

    cout<<findMaxDepth(v)<<endl;
    return 0;
}