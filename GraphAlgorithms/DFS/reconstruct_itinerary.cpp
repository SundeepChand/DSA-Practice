#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<string, int> m;
    vector<string> iti;
    vector<int> beg;

    void dfs(vector<vector<string>> &adj, string src)
    {
        int idx_src = m[src];

        // Visit all the edges of src
        for (int i = beg[idx_src]; i < adj[idx_src].size(); i = beg[idx_src])
        {
            beg[idx_src] = i + 1;
            dfs(adj, adj[idx_src][i]);
        }
        iti.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        int n = tickets.size(), n_nodes = 0;
        for (int i = 0; i < n; i++)
        {
            if (m.find(tickets[i][0]) == m.end())
            {
                m[tickets[i][0]] = n_nodes;
                n_nodes++;
            }
            if (m.find(tickets[i][1]) == m.end())
            {
                m[tickets[i][1]] = n_nodes;
                n_nodes++;
            }
        }

        vector<vector<string>> adj(n_nodes, vector<string>());
        for (int i = 0; i < n; i++)
        {
            adj[m[tickets[i][0]]].push_back(tickets[i][1]);
        }
        for (int i = 0; i < n_nodes; i++)
        {
            sort(adj[i].begin(), adj[i].end());
        }
        beg = vector<int>(n_nodes, 0);

        dfs(adj, "JFK");
        reverse(iti.begin(), iti.end());
        return iti;
    }
};

int main()
{
    return 0;
}