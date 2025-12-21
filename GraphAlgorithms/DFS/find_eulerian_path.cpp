#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<list<int>> adj;
    int n;
    vector<int> eulerPath;

public:
    Graph(int n)
    {
        this->n = n;
        adj = vector<list<int>>(n, list<int>());
    }

    void addEdge(int u, int v, bool directed = false)
    {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }

    void eulerianUtil(int cur)
    {
        while (adj[cur].size() > 0)
        {
            int val = adj[cur].front();
            adj[cur].pop_front();
            adj[val].remove(cur);
            eulerianUtil(val);
        }
        eulerPath.push_back(cur);
    }

    vector<int> eulerianPath()
    {
        // Method to find an Eulerian path in the graph
        int oddNodes = 0, begNode = 0;
        for (int i = 0; i < n; i++)
            if (adj[i].size() % 2 == 1)
            {
                oddNodes++;
                begNode = i;
            }

        if (oddNodes != 0 && oddNodes != 2)
        {
            cout << "No valid solution" << endl;
            return vector<int>();
        }

        // Now we can generate out eulerian path
        // we need to start at beg node
        // stack<int> s;
        // s.push(begNode);
        // int curNode = begNode;
        // while (!s.empty())
        // {
        //     // Visit an unvisited edge at the current node
        //     if (adj[curNode].size() > 0)
        //     {
        //         int prev = curNode;
        //         curNode = adj[curNode].front();
        //         s.push(curNode);
        //         adj[prev].pop_front();
        //     }
        //     else
        //     {
        //         eulerPath.push_back(curNode);
        //         curNode = s.top();
        //         s.pop();
        //     }
        // }
        // eulerPath.push_back(curNode);
        eulerianUtil(begNode);
        return eulerPath;
    }

    void printEulerianPath()
    {
        for (auto x : eulerPath)
            cout << x << " -> ";
        cout << endl;
    }
};

int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(0, 3);
    g1.addEdge(4, 3);
    g1.eulerianPath();
    g1.printEulerianPath();

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.eulerianPath();
    g2.printEulerianPath();

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.eulerianPath();
    g3.printEulerianPath();

    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.eulerianPath();
    g4.printEulerianPath();

    // Let us create a graph with all vertices
    // with zero degree
    Graph g5(3);
    g5.eulerianPath();
    g5.printEulerianPath();

    return 0;
}