#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getNodes(bool graph[101][101], int n, int cur, int m, vector<int> &color)
{
    vector<vector<int>> res(2);
    set<int> s;
    for (int i = 0; i < m; i++)
        s.insert(i);

    for (int i = 0; i < n; i++)
    {
        if (graph[cur][i] == 1)
        {
            s.erase(color[i]);
            if (color[i] == -1)
                res[0].push_back(i);
        }
    }
    res[1] = vector<int>(s.begin(), s.end());
    return res;
}

// that no two adjacent vertices of graph are coloured with same colour.
bool dfs(bool graph[101][101], int cur, int m, int n, int &coloredCount, vector<int> &color)
{
    vector<vector<int>> nodes = getNodes(graph, n, cur, m, color);
    vector<int> &nbrs = nodes[0], &avColors = nodes[1];

    cout << "DEB: " << cur << " " << avColors.size() << endl;

    if (nbrs.size() == 0)
        return avColors.size() >= 1;

    bool res = false;
    for (auto c : avColors)
    {
        color[cur] = c;
        coloredCount++;
        for (auto nbr : nbrs)
        {
            res = res or dfs(graph, nbr, m, n, coloredCount, color);
        }
        if (res)
            return res;
        color[cur] = -1;
        coloredCount--;
    }
    return res;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    set<int> colors;
    for (int i = 0; i < m; i++)
    {
        colors.insert(i);
    }

    vector<int> color(n, -1);
    int coloredCount = 0;
    bool solved = true;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            solved = solved and dfs(graph, i, m, n, coloredCount, color);
        }
    }
    return solved;
}