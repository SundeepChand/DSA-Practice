// https://leetcode.com/discuss/post/6244752/google-l3-interview-experience-questions-2utz/
/*
Onsite round 3 : Play songs in order
There are n people and each person has a specific order in
which the songs should be played,
P1 : a,b,c
P2. : b, e , f
We have to find if we can find a valid order, if there is a
valid order we have to return that, this is a topological ordering problem
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool topoSortUtil(vector<vector<int>> &adj, int i, vector<int> &color, vector<int> &ord)
    {
        color[i] = 1;

        bool hasCycle = false;

        for (auto nbr : adj[i])
        {
            if (color[nbr] == 0)
            {
                hasCycle = hasCycle or topoSortUtil(adj, nbr, color, ord);
            }
            else if (color[nbr] == 1)
            {
                hasCycle = true;
                break;
            }
        }
        color[i] = 2;
        ord.push_back(i);
        return hasCycle;
    }

public:
    vector<int> getSongsOrder(vector<vector<int>> &adj)
    {
        int n = adj.size();

        vector<int> color(n, 0);
        vector<int> ord;

        bool hasCycle = false;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
            {
                hasCycle = hasCycle or topoSortUtil(adj, i, color, ord);
                if (hasCycle)
                {
                    return vector<int>();
                }
            }
        }
        reverse(ord.begin(), ord.end());
        return ord;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int id = 0;
    unordered_map<string, int> mp;
    unordered_map<int, string> mpRev;

    vector<vector<int>> edges;

    while (n--)
    {
        int songs;
        cin >> songs;

        vector<string> ordSongs;

        while (songs--)
        {
            string cur;
            cin >> cur;

            ordSongs.push_back(cur);

            if (mp.find(cur) == mp.end())
            {
                mp[cur] = id;
                mpRev[id] = cur;
                id++;
            }
        }

        for (int i = 1; i < ordSongs.size(); i++)
        {
            edges.push_back({mp[ordSongs[i - 1]], mp[ordSongs[i]]});
        }
    }

    // Build the adj list
    vector<vector<int>> adj(id, vector<int>());
    for (auto e : edges)
    {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
    }

    cout << "Adj:\n";
    for (int i = 0; i < id; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    Solution s;
    vector<int> songsOrder = s.getSongsOrder(adj);
    cout << "\nOrder of songs:" << endl;
    for (int x : songsOrder)
    {
        cout << mpRev[x] << ", ";
    }
    cout << endl;
    return 0;
}