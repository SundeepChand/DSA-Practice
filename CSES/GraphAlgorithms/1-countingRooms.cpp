#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

void bfs(vector<string> &v, int i, int j)
{
    int n = v.size(), m = v[0].length();
    queue<pair<int, int>> q;
    q.push({i, j});
    v[i][j] = '#';
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for (int x = 0; x < 4; x++)
        {
            int nr = r + dr[x], nc = c + dc[x];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] == '.')
            {
                q.push({nr, nc});
                v[nr][nc] = '#';
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

    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
            {
                bfs(v, i, j);
                ctr++;
            }
        }
    }
    cout << ctr << endl;
    return 0;
}