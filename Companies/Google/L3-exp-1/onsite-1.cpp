/*
Onsite round 1 :
Android phone patterns : Given n,m which are a set of points,
we have to find the total possible unique patterns that can be
drawn, min len of a pattern is 1, n,m >=1

https://leetcode.com/problems/android-unlock-patterns/description/
*/
// https://leetcode.com/discuss/post/6244752/google-l3-interview-experience-questions-2utz/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// This needs to be solved using backtracking
// https://algo.monster/liteproblems/351
// REVISIT THIS
class Solution
{

private:
    int solveForXNodesUtil(int n, int m, int i, int j, int x, set<vector<int>> &visited)
    {
        if (x == 0)
        {
            return 1;
        }
        int di[] = {0, 0, -1, -1, -1, 1, 1, 1, 2, 2, -2, -2, -1, 1, -1, 1};
        int dj[] = {-1, 1, -1, 0, 1, -1, 0, 1, 1, -1, 1, -1, 2, 2, -2, -2};

        int res = 0;

        visited.insert({i, j});

        for (int y = 0; y < 16; y++)
        {
            int ni = i + di[y], nj = j + dj[y];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m && visited.find({ni, nj}) == visited.end())
            {
                res = (res + solveForXNodesUtil(n, m, ni, nj, x - 1, visited)) % MOD;
            }
        }
        visited.erase({i, j});

        return res;
    }

    int solveForXNodes(int n, int m, int x)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                set<vector<int>> visited;
                res = (res + solveForXNodesUtil(n, m, i, j, x - 1, visited)) % MOD;
            }
        }
        return res;
    }

public:
    int solve(int n, int m)
    {
        int res = 0;
        // Min path should contain 2 nodes (points), max path can contain (n * m) nodes.
        for (int i = 1; i <= n * m; i++)
        {
            res = (res + solveForXNodes(n, m, i)) % MOD;
        }
        return res;
    }
};

// This solution is for 3 x 3 grid only
class SolutionGfg
{
public:
#define DOTS 10

    //  method to find total pattern starting from current cell
    int totalPatternFromCur(bool visit[DOTS], int jump[DOTS][DOTS],
                            int cur, int toTouch)
    {
        if (toTouch <= 0)
        {
            //  if last cell then return 1 way
            return (toTouch == 0) ? 1 : 0;
        }

        int ways = 0;

        //  make this cell visited before going to next call
        visit[cur] = true;

        for (int i = 1; i < DOTS; i++)
        {
            /*  if this cell is not visit AND
                either i and cur are adjacent (then jump[i][cur] = 0)
                or between cell must be visit already (
                then visit[jump[i][cur]] = 1)   */
            if (!visit[i] && (!jump[i][cur] || visit[jump[i][cur]]))
                ways += totalPatternFromCur(visit, jump, i, toTouch - 1);
        }

        //  make this cell not visited after returning from call
        visit[cur] = false;

        return ways;
    }

    //  method returns number of 3 x 3
    int solve(int n, int m)
    {
        int jump[DOTS][DOTS] = {0};

        //  2 lies between 1 and 3
        jump[1][3] = jump[3][1] = 2;

        //  8 lies between 7 and 9
        jump[7][9] = jump[9][7] = 8;

        //  4 lies between 1 and 7
        jump[1][7] = jump[7][1] = 4;

        //  6 lies between 3 and 9
        jump[3][9] = jump[9][3] = 6;

        //  5 lies between 1, 9  2, 8  3, 7 and 4, 6
        jump[1][9] = jump[9][1] = jump[2][8] = jump[8][2] = jump[3][7] = jump[7][3] = jump[4][6] = jump[6][4] = 5;

        bool visit[DOTS] = {0};
        int ways = 0;
        for (int i = 1; i <= 9; i++)
        {
            //  1, 3, 7, 9 are symmetric so multiplying by 4
            ways += 4 * totalPatternFromCur(visit, jump, 1, i - 1);

            //  2, 4, 6, 8 are symmetric so multiplying by 4
            ways += 4 * totalPatternFromCur(visit, jump, 2, i - 1);

            ways += totalPatternFromCur(visit, jump, 5, i - 1);
        }

        return ways;
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
    SolutionGfg sgfg;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        cout << s.solve(n, m) << " " << sgfg.solve(n, m) << endl;
    }
    return 0;
}