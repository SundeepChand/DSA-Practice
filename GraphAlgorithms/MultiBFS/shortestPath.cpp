#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1)
        {
            q.push({0, i});
            visited[0][i] = true;
            dist[0][i] = 0;
        }
    }

    int ans = -1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int r = cur.first, c = cur.second;
        if (r == n - 1 && ans == -1)
            ans = dist[r][c];
        vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1 && !visited[nr][nc])
            {
                q.push({nr, nc});
                visited[nr][nc] = true;
                dist[nr][nc] = 1 + dist[r][c];
            }
        }
    }

    cout << "DIST:" << endl;
    for (auto x : dist)
    {
        for (auto y : x)
        {
            if (y == INT_MAX)
                cout << "# ";
            else
                cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Min dist = " << ans << endl;
    return 0;
}