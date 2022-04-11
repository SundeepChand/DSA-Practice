#include <bits/stdc++.h>
using namespace std;

int solveBruteForce(vector<vector<int>> &info, int cur, int endPrev)
{
    int n = info.size();

    if (cur >= n)
        return 0;

    int ans = 1 + solveBruteForce(info, cur + 1, endPrev);
    if (info[cur][0] - info[cur][1] >= endPrev)
        ans = min(ans, solveBruteForce(info, cur + 1, info[cur][0] + info[cur][1]));
    return ans;
}

int solveGreedy(vector<vector<int>> &info)
{
    int n = info.size();
    for (int i = 0; i < n; i++)
    {
        int c = info[i][0], r = info[i][1];
        info[i][0] = c + r, info[i][1] = c - r;
    }

    sort(info.begin(), info.end());

    int ans = 0, curEnd = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (info[i][1] < curEnd)
            ans++;
        else
            curEnd = info[i][0];
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

    int n;
    cin >> n;

    vector<vector<int>> info(n);

    for (int i = 0; i < n; i++)
    {
        int c, r;
        cin >> c >> r;

        info[i] = {c, r};
    }
    sort(info.begin(), info.end());

    cout << solveBruteForce(info, 0, INT_MIN) << endl;
    cout << solveGreedy(info) << endl;
    return 0;
}