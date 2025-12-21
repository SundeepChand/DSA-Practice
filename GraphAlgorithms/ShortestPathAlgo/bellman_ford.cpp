/*

Steps in Bellman Ford Algorithm
_______________________________
1) Init dist[vertices] = INT_MAX, dist[src] = 0
2) Relax all edges V - 1 times (Most Imp)
3) Negative Weight Cycle Detection

*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> edges; // [u, v, w]
    int n;

public:
    Graph(int n)
    {
        this->n = n;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
    }

    vector<int> bellmanFord(int src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            // Relax all the edges
            for (int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        // Detect -ve weight cycle
        bool has_cycle = false;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                has_cycle = true;
            }
        }
        if (has_cycle)
            return vector<int>();

        return dist;
    }
};

int main()
{
    int n = 3;
    Graph g(n);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, -2);
    g.addEdge(2, 0, 1);

    int src = 0;
    vector<int> dist = g.bellmanFord(src);
    if (dist.size() == 0)
        cout << "Graph contains negative weight cycle." << endl;
    else
    {
        for (int i = 0; i < dist.size(); i++)
        {
            cout << src << " -> " << i << ": ";
            if (dist[i] == INT_MAX)
            {
                cout << "INT_MAX";
            }
            else
            {
                cout << dist[i];
            }
            cout << endl;
        }
    }
    return 0;
}