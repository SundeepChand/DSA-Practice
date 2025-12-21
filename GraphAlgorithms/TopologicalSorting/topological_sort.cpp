#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adj;
    int n;

public:
    Graph() : n(0) {}
    Graph(int n)
    {
        this->n = n;
        adj = vector<vector<int>>(n, vector<int>());
    }
    void addEdge(int u, int v)
    {
        // Create a directed edge from u to v
        adj[u].push_back(v);
    }

    void topologicalOrderBFS()
    {
        // Find the topological order using BFS (Kahn's Algorithm)

        // Find the indegree of each of the nodes.
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            cout << cur << ", ";
            for (int nbr : adj[cur])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        cout << endl;
    }

    void DFSUtil(int cur, vector<bool> &visited, vector<int> &sortedOrder)
    {
        visited[cur] = true;

        for (int nbr : adj[cur])
        {
            if (!visited[nbr])
            {
                DFSUtil(nbr, visited, sortedOrder);
            }
        }

        sortedOrder.push_back(cur);
    }

    void topologicalOrderDFS()
    {
        // Find the topological ordering using DFS.

        vector<bool> visited(n, false);
        vector<int> sortedOrder;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFSUtil(i, visited, sortedOrder);
            }
        }

        reverse(sortedOrder.begin(), sortedOrder.end());
        for (auto x : sortedOrder)
            cout << x << ", ";
        cout << endl;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);

    cout << "Topological Order with BFS: ";
    g.topologicalOrderBFS();

    cout << "Topological Order with DFS: ";
    g.topologicalOrderDFS();

    return 0;
}