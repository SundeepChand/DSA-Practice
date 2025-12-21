#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBpt;

    void bfs(vector<vector<int>> &graph, int i, vector<int> color)
    {
        int cur_color = 0;
        int cur = i;

        // Perform BFS traversal and note the colors
        queue<int> q;
        q.push(cur);
        color[cur] = cur_color;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            cur_color = !color[cur];

            for (int x : graph[cur])
            {
                if (color[x] == -1)
                {
                    q.push(x);
                    color[x] = cur_color;
                }
                else if (color[x] == color[cur])
                {
                    isBpt = false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        isBpt = true;

        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                bfs(graph, i, color);
                if (!isBpt)
                    return isBpt;
            }
        }

        return isBpt;
    }
};

int main()
{
    return 0;
}