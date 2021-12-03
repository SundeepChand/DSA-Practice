#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

void bfs(vector<vector<char>> &grid, int a, int b)
{
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> nbr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                nbr[i][j] = INT_MAX;
                continue;
            }
            vector<int> di = {-1, 1, 0, 0};
            vector<int> dj = {0, 0, -1, 1};
            for (int x = 0; x < 4; x++)
            {
                int ni = i + di[x], nj = j + dj[x];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && (grid[ni][nj] == '.' || grid[ni][nj] == 'L'))
                {
                    nbr[i][j]++;
                }
            }
        }
    }

    // for (auto x : nbr)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        int i = cur.first, j = cur.second;
        q.pop();

        vector<int> di = {-1, 1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};
        for (int x = 0; x < 4; x++)
        {
            int ni = i + di[x], nj = j + dj[x];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '.' && nbr[ni][nj] > 0 && nbr[ni][nj] <= 2 && !visited[ni][nj])
            {
                grid[ni][nj] = '+';
                q.push({ni, nj});
                visited[ni][nj] = 1;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));
        int i1 = 0, j1 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'L')
                {
                    i1 = i, j1 = j;
                }
            }
        }

        bfs(grid, i1, j1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}