#include <bits/stdc++.h>
using namespace std;

// Perform multi-source bfs & find in how many days food supply will reach each of the cities.
// . represents a city & + represents a factory
// It takes 1 day for food to be supplied to a single city.
vector<vector<int>> get_dist(const vector<string> &adj)
{
    int n = adj.size(), m = adj[0].length();
    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == '+')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int a = cur.first, b = cur.second;
        q.pop();

        vector<int> dy = {-1, 0, 1, 0};
        vector<int> dx = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            if (
                (a + dy[i] >= 0) &&
                (a + dy[i] < n) &&
                (b + dx[i] >= 0) &&
                (b + dx[i] < m) &&
                (dist[a + dy[i]][b + dx[i]] == -1))
            {
                q.push({a + dy[i], b + dx[i]});
                dist[a + dy[i]][b + dx[i]] = 1 + dist[a][b];
            }
        }
    }
    return dist;
}

int main()
{
    int n = 5;
    vector<string> input_graph = {
        "..+...",
        "......",
        "....+.",
        "+.....",
        "......"};

    vector<vector<int>> dist = get_dist(input_graph);
    for (vector<int> x : dist)
    {
        for (int y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}