#include <bits/stdc++.h>
using namespace std;

string reachTheEnd(vector<string> grid, int maxTime)
{
    // Perform BFS
    queue<pair<int, int>> q;

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));

    q.push({ 0, 0 });
    dist[0][0] = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int i = cur.first, j = cur.second;
        grid[i][j] = '#';
        q.pop();

        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, 1, 0, -1};

        for (int x = 0; x < 4; x++)
        {
            int ni = i + di[x], nj = j + dj[x];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '.')
            {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ ni, nj });
            }
        }
    }

    if (dist[n - 1][m - 1] == -1)
        return "No";
    if (dist[n - 1][m - 1] <= maxTime)
        return "Yes";
    return "No";
}

int main()
{
    vector<string> v = {
        "..##",
        "#.##",
        "#.#."
    };

    vector<string> v2 = {
        ".#",
        "#."
    };
    cout<<reachTheEnd(v2, 7)<<endl;
    return 0;
}