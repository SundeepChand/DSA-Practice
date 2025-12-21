#include <bits/stdc++.h>
using namespace std;

pair<int, int> lis(vector<int> const& v, vector<int> &p)
{
    int n = v.size();
    p = vector<int>(n, -1);
    vector<int> dp(n, 1);
    int ans = 1, end = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                p[i] = j;
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            end = i;
        }
    }
    return {ans, end};
}

int main()
{
    vector<int> v {50, 3, 10, 7, 40, 80};
    vector<int> p;

    pair<int, int> ans = lis(v, p);
    cout<<"Length of LIS: "<<ans.first<<endl;
    cout<<"LIS:"<<endl;

    int cur = ans.second;
    do {
        cout<<v[cur]<<", ";
        cur = p[cur];
    } while (cur != -1);
    cout<<endl;

    return 0;
}