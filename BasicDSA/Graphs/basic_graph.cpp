#include <bits/stdc++.h>
using namespace std;

class UWGraph
{
public:
    int n;
    vector<vector<int>> adj;

    UWGraph() : n(0) {}
    UWGraph(int n)
    {
        this->n = n;
        adj = vector<vector<int>>(n, vector<int>());
    }

    void addEdge(int u, int v, bool directed = false)
    {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }

    void printAdjMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            for (auto x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main()
{
    UWGraph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(4, 2);

    g.printAdjMatrix();
    return 0;
}