#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

// #define INF 100000000
#define INF 1000000

vector<int> bfs(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<int> dist(n, INF);

    queue<int> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto nbr : adj[cur])
        {
            if (dist[nbr] > 1 + dist[cur])
            {
                dist[nbr] = 1 + dist[cur];
                vis[nbr] = true;
                q.push(nbr);
            }
        }
    }
    return dist;
}

int getShortestPath(int h, int w, vector<string> &grid)
{
    vector<vector<int>> adj(h * w, vector<int>()), rev(h * w, vector<int>());

    vector<int> di = {0, 0, -1, 1, -1, -1, 1, 1};
    vector<int> dj = {-1, 1, 0, 0, -1, 1, -1, 1};

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int curNode = w * i + j;

            if (grid[i][j] == '.')
                continue;

            int start = 0, end = 0;
            if (grid[i][j] == '+')
            {
                start = 0, end = 4;
            }
            else
                start = 4, end = 8;
            for (int k = start; k < end; k++)
            {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 and nj >= 0 and ni < h and nj < w)
                {
                    int nbrNode = w * ni + nj;
                    adj[curNode].push_back(nbrNode);
                    rev[nbrNode].push_back(curNode);
                }
            }
        }
    }

    vector<int> distFromStart = bfs(adj, 0);
    vector<int> distFromEnd = bfs(rev, w * h - 1);

    int ans = distFromStart[w * h - 1];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.')
            {
                int curNode = w * i + j;
                for (int k = 0; k < 8; k++)
                {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni >= 0 and nj >= 0 and ni < h and nj < w)
                    {
                        int nbrNode = w * ni + nj;
                        if (distFromStart[curNode] != INF and distFromEnd[nbrNode] != INF)
                        {
                            ans = min(ans, distFromStart[curNode] + distFromEnd[nbrNode] + 1);
                        }
                    }
                }
            }
        }
    }
    return ans == INF ? -1 : (ans + 1);
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
        int h, w;
        cin >> h >> w;

        vector<string> v(h);
        for (int i = 0; i < h; i++)
            cin >> v[i];

        cout << getShortestPath(h, w, v) << endl;
    }
    return 0;
}