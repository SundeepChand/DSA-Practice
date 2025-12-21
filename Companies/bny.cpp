#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int findMinimumTime(int nodes, vector<int> from, vector<int> to, vector<int> status)
{
    int e = from.size();

    vector<vector<int>> adj(nodes, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int u = from[i] - 1, v = to[i] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vector<bool> visited(nodes, false);
    int nWhite = 0;
    for (int i = 0; i < nodes; i++)
    {
        if (status[i] == 3)
        {
            q.push(i);
            visited[i] = true;
        }
        else if (status[i] == 1)
            nWhite++;
    }

    int time = 0;
    while (!q.empty() and nWhite > 0)
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int front = q.front();
            q.pop();

            for (int nbr : adj[front])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                    if (status[nbr] == 1)
                        nWhite--;
                }
            }
        }
        time++;
    }
    return time;
}

int getMinCost(vector<int> cost, vector<int> time)
{
    sort(time.begin(), time.end(), greater<int>());

    int i = 0, j = time.size() - 1, minCost = 0;

    while (i <= j)
    {
        int curPaid = time[i], sumSmaller = 0;
        minCost += cost[i];
        while (j > i and sumSmaller < curPaid)
        {
            sumSmaller++;
            j--;
        }
        i++;
    }
    return minCost;
}

vector<int> findPoint(vector<vector<int>> lines)
{
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
    }
    return 0;
}