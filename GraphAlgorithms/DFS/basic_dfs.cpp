#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int n;
    vector<vector<int>> adj;
    vector<int> dist, parent;

public:
    Graph(int n)
    {
        this->n = n;
        adj = vector<vector<int>>(n);
        dist = parent = vector<int>(n, -1);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(int src)
    {
        dist = parent = vector<int>(n, -1);

        queue<int> q;
        q.push(src);

        vector<bool> visited(n, false);
        visited[src] = true;
        dist[src] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int nbr : adj[cur])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = cur;
                    dist[nbr] = 1 + dist[cur];
                    q.push(nbr);
                }
            }
        }
    }

    void dfsUtil(int src, int parent, vector<bool> &visited)
    {
        dist[src] = (parent == -1 ? 0 : (1 + dist[parent]));
        this->parent[src] = parent;
        visited[src] = true;

        // Visit all the neighbors of src in depth-first order.
        for (auto x : adj[src])
        {
            if (!visited[x])
            {
                dfsUtil(x, src, visited);
            }
        }
    }

    void dfs(int src)
    {
        dist = parent = vector<int>(n, -1);

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfsUtil(i, -1, visited);
            }
        }
    }

    void print_dist()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " - " << dist[i] << endl;
        }
        cout << endl;
    }

    vector<int> get_path(int u, int v)
    {
        // Find the path from u to v
        vector<int> path;
        int cur = v;
        while (cur != -1 && cur != u)
        {
            path.push_back(cur);
            cur = parent[cur];
        }
        if (cur != -1)
            path.push_back(cur);
        else
            return vector<int>();
        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.dfs(0);

    g.print_dist();
    vector<int> path = g.get_path(0, 3);
    cout << "Path from 0 to 3: ";
    for (auto x : path)
        cout << x << ", ";
    return 0;
}