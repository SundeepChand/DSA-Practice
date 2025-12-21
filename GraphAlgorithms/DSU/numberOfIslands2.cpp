#include <bits/stdc++.h>
using namespace std;

class Solution
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
                if (rank[pa] > rank[pb])
                {
                    parent[pb] = pa;
                    rank[pa] += rank[pb];
                }
                else
                {
                    parent[pa] = pb;
                    rank[pb] += rank[pa];
                }
            }
        }
    };

    vector<int> numIslands(int n, int m, vector<pair<int, int>> positions)
    {
        vector<vector<bool>> grid(n, vector<bool>(m, 0));

        DSU d(n * m);

        vector<int> ans;
        int ctr = 0;
        for (int i = 0; i < positions.size(); i++)
        {
            int r = positions[i].first, c = positions[i].second;
            if (grid[r][c] == 1)
            {
                ans.push_back(ctr);
                continue;
            }
            grid[r][c] = 1;
            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};
            set<int> components;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                {
                    components.insert(d.root(nr * m + nc));
                }
            }
            if (components.size() == 0)
                ctr++;
            else
                ctr = ctr + 1 - components.size();
            ans.push_back(ctr);
            for (auto x : components)
            {
                d.Union(x, r * m + c);
            }
        }
        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    Solution s;
    vector<int> count = s.numIslands(n, m, v);
    for (auto x : count)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}