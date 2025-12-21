#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

void bfs(vector<string> &mat, pair<int, int> src, pair<int, int> &dest, vector<vector<pair<int, int>>> &parent)
{
    int n = mat.size(), m = mat[0].length();

    queue<pair<int, int>> q;
    q.push(src);

    while (!q.empty())
    {
        auto cur = q.front();
        int r = cur.first, c = cur.second;
        q.pop();

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] != '#')
            {
                q.push({nr, nc});
                parent[nr][nc] = cur;
                if (mat[nr][nc] == 'B')
                {
                    dest = {nr, nc};
                    return;
                }
                mat[nr][nc] = '#';
            }
        }
    }
}

string get_path(pair<int, int> &dest, pair<int, int> &src, vector<vector<pair<int, int>>> &parent)
{
    string path = "";
    pair<int, int> cur = dest;
    while (cur != src)
    {
        auto parent_cur = parent[cur.first][cur.second];
        if (parent_cur.first == cur.first)
        {
            if (parent_cur.second - cur.second < 0)
                path.push_back('R');
            else if (parent_cur.second - cur.second > 0)
                path.push_back('L');
        }
        else if (parent_cur.second == cur.second)
        {
            if (parent_cur.first - cur.first < 0)
                path.push_back('D');
            else if (parent_cur.first - cur.first > 0)
                path.push_back('U');
        }
        cur = parent_cur;
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
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    // Perform BFS from source
    pair<int, int> src;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A')
                src = {i, j};
        }
    }

    pair<int, int> dest = {-1, -1};
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    bfs(mat, src, dest, parent);

    if (dest == make_pair(-1, -1))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        string path = get_path(dest, src, parent);
        cout << path.length() << endl;
        cout << path << endl;
    }

    return 0;
}