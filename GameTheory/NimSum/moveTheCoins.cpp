#include <bits/stdc++.h>
using namespace std;

// This problem is based on stair-case nim.

void addEdge(vector<set<int>> &adj, int a, int b)
{
    adj[a].insert(b);
    adj[b].insert(a);
}

// This is a brute force solution. And this gives TLE on submission
string solve(vector<set<int>> adj, vector<int> &c, int u, int v)
{
    // Modify the tree
    for (auto x: adj[u])
    {
        if (adj[x].find(u) != adj[x].end())
        {
            // This is the parent of u
            adj[x].erase(u);
            adj[u].erase(x);
            adj[v].insert(u);
            adj[u].insert(v);
            break;
        }
    }
    
    int n = adj.size();
    vector<bool> visited(n, false);
    int xr = 0;
    // Perform BFS
    queue<int> q;
    q.push(0);
    int sz = 1, level = 0;
    while (!q.empty())
    {
        for (int i = 0; i < sz; i++)
        {
            int cur = q.front();
            visited[cur] = true;
            if (level % 2 == 1)
            {
                xr ^= c[cur];
            }
            q.pop();

            for (int x: adj[cur])
            {
                if (!visited[x])
                {
                    q.push(x);
                }
            }
        }
        sz = q.size();
        level++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return "INVALID";
        }
    }
    if (xr == 0)
        return "NO";
    return "YES";
}

int main() {
    int n;
    cin>>n;
    
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    
    vector<set<int>> adj(n, set<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        addEdge(adj, a, b);
    }
    
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin>>u>>v;
        
        cout<<solve(adj, c, u - 1, v - 1)<<endl;
    }
    return 0;
}