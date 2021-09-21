// https://www.hackerrank.com/challenges/chessboard-game-again-1/problem

// Here we recursively calculate the grundy values for each position and take their XOR
// to find the total grundy value
#include <bits/stdc++.h>
using namespace std;

int dp[15][15];
int mex(unordered_set<int> u)
{
    for (int i = 0;; i++)
        if (u.find(i) == u.end())
            return i;
    return -1;
}

int grundy(int x, int y)
{
    if (x < 0 || y < 0 || x >= 15 || y >= 15)
        return -1;
    if (x <= 1 && y <= 1)
        return (dp[x][y] = 0);
    if (dp[x][y] != -1)
        return dp[x][y];

    unordered_set<int> vals;
    vals.insert(grundy(x - 2, y - 1));
    vals.insert(grundy(x - 2, y + 1));
    vals.insert(grundy(x - 1, y - 2));
    vals.insert(grundy(x + 1, y - 2));

    return (dp[x][y] = mex(vals));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));

        int k;
        cin >> k;

        int xr = 0;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            xr ^= grundy(x, y);
        }

        if (xr == 0)
            cout << "Second";
        else
            cout << "First";
        cout << endl;
    }
}