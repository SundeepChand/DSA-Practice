#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> cost;
    vector<vector<int>> dp;
    int n;

public:
    Graph(int n, vector<vector<int>> cost)
    {
        this->n = n;
        this->cost = cost;
        dp = vector<vector<int>>(1 << n, vector<int>(n, -1));
    }

    int minCost(int visited, int cur, int src)
    {
        if (visited == ((1 << n) - 1))
            return cost[cur][src];

        if (dp[visited][cur] != -1)
            return dp[visited][cur];

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if ((visited & (1 << i)) == 0)
                ans = min(
                    ans,
                    cost[cur][i] + minCost((visited | (1 << i)), i, src));
        }
        return (dp[visited][cur] = ans);
    }

    int TSP()
    {
        int visited = 1, src = 0;
        return minCost(visited, 0, 0);
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> cost = {{0, 10, 34, 25},
                                {10, 0, 20, 42},
                                {34, 20, 0, 20},
                                {25, 42, 20, 0}};
    Graph g(n, cost);

    int minCost = g.TSP();
    cout << minCost << endl;
    return 0;
}