#include <bits/stdc++.h>
using namespace std;

// Not working
class Graph
{
private:
    int n;
    vector<vector<int>> cost;
    vector<int> parent;

public:
    Graph(int n, vector<vector<int>> cost)
    {
        this->n = n;
        this->cost = cost;
        parent = vector<int>(n, -1);
    }
    int minCost(int visited, int cur)
    {
        if (visited == ((1 << n) - 1))
        {
            parent[cur] = 0;
            return cost[cur][0];
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if ((visited & (1 << i)) == 0)
            {
                int temp = cost[cur][i] + minCost(visited | (1 << i), i);
                if (temp < ans)
                {
                    ans = temp;
                    cout << "DEB: " << i << ", " << cur << endl;
                    parent[cur] = i;
                }
            }
        }
        return ans;
    }
    int TSPCost()
    {
        int visited = 1, src = 0;
        return minCost(visited, src);
    }
    vector<int> TSPPath()
    {
        cout << "Path: ";
        vector<int> path;
        for (auto x : parent)
        {
            cout << x << " ";
        }
        cout << endl;
        return path;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> cost = {{0, 2, 1, 2},
                                {2, 0, 3, 1},
                                {1, 3, 0, 4},
                                {2, 1, 4, 0}};
    Graph g(n, cost);

    int minCost = g.TSPCost();
    cout << "Cost: " << minCost << endl;
    g.TSPPath();
    return 0;
}