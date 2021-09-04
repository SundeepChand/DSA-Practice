#include <bits/stdc++.h>
using namespace std;

vector<int> lcs(const vector<int> &a, const vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while (i != 0 && j != 0 && dp[i][j] != 0)
    {
        if (a[i - 1] == b[j - 1] && dp[i][j] == 1 + dp[i - 1][j - 1])
        {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
        {
            i--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

vector<int> lis(const vector<int> &v)
{
    int n = v.size();
    if (n <= 0)
        return vector<int>();
    vector<int> dp(n), parent(n, -1);
    dp[0] = 1;

    int end_idx = 0, len_lis = 1;
    for (int i = 1; i < n; i++)
    {
        int longest_subseq = 0, idx = - 1;;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && dp[j] > longest_subseq)
            {
                longest_subseq = dp[j];
                idx = j;
            }
        }
        dp[i] = 1 + longest_subseq;
        parent[i] = idx;
        if (dp[i] > len_lis)
        {
            len_lis = dp[i];
            end_idx = i;
        }
    }

    // Reconstruct the lis from parent array.
    vector<int> ans;
    while (end_idx != -1)
    {
        ans.push_back(v[end_idx]);
        end_idx = parent[end_idx];
    }
    // cout<<"Test: "<<ans.size()<<", "<<len_lis<<endl;
    reverse(ans.begin(), ans.end());
    assert(len_lis == ans.size());
    return ans;
}

/*
Input:
9
7 4 4 5 0 6 5 4 10
4
5 2 10 9

Expected Output:
2
5 10
*/

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int m;
    cin>>m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }

    vector<int> v = lcs(a, b);

    cout<<"LCS:"<<endl;
    for (auto x: v)
    {
        cout<<x<<" ";
    }

    // vector<int> ans = lis(v);
    // cout<<ans.size()<<endl;
    // for (auto x: ans)
    // {
    //     cout<<x<<" ";
    // }
    return 0;
}