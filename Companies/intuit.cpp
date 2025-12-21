#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int x, int y)
{
    int cz = 0, co = 0, ans = 0;
    map<int, int> mp;
    for (int x : a)
    {
        if (x == 0)
            cz++;
        else
            co++;
        if ((double(cz) / co) == (double(x) / y))
            ans++;
        ans += mp[y * cz - x * co];
        mp[y * cz - x * co]++;
    }
    return ans;
}

int getMinDist(vector<vector<int>> &A, int row, int &vis)
{
    int n = A.size() - 2;
    if (vis == ((1 << n) - 1))
        return 0;

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (((vis >> i) & 1) == 0)
            ans = min(ans, A[row][i] + getMinDist(A, ));
    }
}

int solve2(int n, int x, int y, vector<vector<int>> &A)
{
    int vis = 1;
    int minDist = getMinDist(A, 0, 1, vis);
}

int solve3(string S, char c1, char c2)
{
    int n = S.size();
    vector<vector<int>> v(26);
    for (int i = 0; i < n; i++)
        v[c - 'a'].push_back(i);

    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (i == c1 or i == c2)
        {
            for (int j = 1; j < v[i - 'a'].size(); j++)
                ans += abs(v[i - 'a'][j] - v[i - 'a'][j - 1] - 1);
        }
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
    }
    return 0;
}