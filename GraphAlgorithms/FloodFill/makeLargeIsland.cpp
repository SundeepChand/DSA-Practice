#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    class DSU
    {
    public:
        vector<int> parent, rank;
        int n;

        DSU(int n)
        {
            this->n = n;
            parent = vector<int>(n, -1);
            rank = vector<int>(n, 1);
        }
        int root(int n)
        {
            if (parent[n] == -1)
                return n;
            return parent[n] = root(parent[n]);
        }
        void Union(int a, int b)
        {
            int pa = root(a), pb = root(b);
            if (pa != pb)
            {
                if (rank[pa] < rank[pb])
                {
                    parent[pa] = pb;
                    rank[pb] += rank[pa];
                }
                else
                {
                    parent[pb] = pa;
                    rank[pa] += rank[pb];
                }
            }
        }
        int islandSize(int n)
        {
            int pn = root(n);
            return rank[pn];
        }
    };

    int encode(int n, int i, int j)
    {
        return i * n + j;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> di = {-1, 1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};

        DSU d(n * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k], nj = j + dj[k];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1)
                        {
                            d.Union(encode(n, i, j), encode(n, ni, nj));
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int ctr = 1;
                    set<int> s;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k], nj = j + dj[k];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1)
                        {
                            s.insert(d.root(encode(n, ni, nj)));
                        }
                    }
                    for (int x : s)
                        ctr += d.islandSize(x);
                    ans = max(ans, ctr);
                }
                else
                {
                    ans = max(ans, d.islandSize(encode(n, i, j)));
                }
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j, int ctr)
    {
        int n = grid.size();

        grid[i][j] = -1;

        vector<int> di = {-1, 1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};
        int ans = 1;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1)
            {
                ans += dfs(grid, ni, nj, ctr);
            }
        }
        grid[i][j] = ctr;
        return ans;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int ctr = 2;
        int n = grid.size();
        vector<int> sizes;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int cur = dfs(grid, i, j, ctr);
                    ans = max(ans, cur);
                    sizes.push_back(cur);
                    ctr++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> s;
                    vector<int> di = {-1, 1, 0, 0};
                    vector<int> dj = {0, 0, -1, 1};
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k], nj = j + dj[k];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] != 0)
                        {
                            s.insert(grid[ni][nj]);
                        }
                    }
                    int cur = 1;
                    for (int x : s)
                    {
                        cur += sizes[x - 2];
                    }
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};