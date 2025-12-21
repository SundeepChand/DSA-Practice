// Solution using multi-source BFS
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

string getDirection(pair<int, int> cur, pair<int, int> prev)
{
    if (prev == make_pair(-1, -1) || cur == make_pair(1, -1))
    {
        return "";
    }
    if (cur.SS == prev.SS)
    {
        if (cur.FF - prev.FF < 0)
            return "U";
        else
            return "D";
    }
    else if (cur.FF == prev.FF)
    {
        if (cur.SS - prev.SS < 0)
            return "L";
        else
            return "R";
    }
    return "";
}

string bfs(bool map[1000][1000], pair<int, int> src, int n, int m)
{
    pair<int, int> parent[n][m] = {make_pair(-1, -1)};

    queue<pair<int, int>> q;
    q.push(src);
    map[src.first][src.second] = 0;

    pair<int, int> dest = {-1, -1};

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int r = cur.first, c = cur.second;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == 1)
            {
                parent[nr][nc] = cur;
                map[nr][nc] = 0;
                q.push({nr, nc});
                if (nr == 0 || nr == (n - 1) || nc == 0 || nc == (m - 1))
                {
                    dest = {nr, nc};
                    break;
                }
            }
        }
    }

    if (dest == make_pair(-1, -1))
        return "";

    string path = "";
    pair<int, int> cur = dest;
    while (cur != make_pair(-1, -1))
    {
        path += getDirection(cur, parent[cur.FF][cur.SS]);
        cur = parent[cur.FF][cur.SS];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<string> mat(n);
    vector<vector<bool>> visited1(n, vector<bool>(m, false));
    vector<vector<bool>> visited2(n, vector<bool>(m, false));
    int dm[n][m], dh[n][m];
    memset(dm, -1, sizeof(dm));
    memset(dh, -1, sizeof(dh));

    pair<int, int> src;

    queue<pair<int, int>> q1, q2;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'M')
            {
                q1.push({i, j});
                dm[i][j] = 0;
                visited1[i][j] = true;
            }
            else if (mat[i][j] == 'A')
            {
                q2.push({i, j});
                dh[i][j] = 0;
                src = {i, j};
                visited2[i][j] = true;
            }
        }
    }

    while (!q1.empty())
    {
        auto cur = q1.front();
        q1.pop();

        int r = cur.first, c = cur.second;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] != '#' && !visited1[nr][nc])
            {
                dm[nr][nc] = 1 + dm[r][c];
                q1.push({nr, nc});
                visited1[nr][nc] = true;
            }
        }
    }

    while (!q2.empty())
    {
        auto cur = q2.front();
        q2.pop();

        int r = cur.first, c = cur.second;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] != '#' && !visited2[nr][nc])
            {
                dh[nr][nc] = 1 + dh[r][c];
                q2.push({nr, nc});
                visited2[nr][nc] = true;
            }
        }
    }

    bool map[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = (!((mat[i][j] == '#') || (dh[i][j] >= dm[i][j])) || (dm[i][j] == -1 && mat[i][j] != '#'));
        }
    }

    string path = bfs(map, src, n, m);
    if (path.length() > 0)
    {
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    }
    else if (src.first == 0 || src.first == (n - 1) || src.second == 0 || src.second == (m - 1))
    {
        cout << "YES" << endl;
        cout << 0 << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}