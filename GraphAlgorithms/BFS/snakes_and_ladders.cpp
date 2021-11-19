#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> decode(int cur, int n)
    {
        int r = cur / n;
        int c = cur % n;
        if (r % 2 == 1)
            c = n - c - 1;
        r = n - r - 1;
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        // Perform BFS to find the shortest dist
        // If a cell is the start of snake/ladder then add an edge
        int n = board.size();
        int ns = n * n;

        int i = 0;
        vector<int> dist(ns, INT_MAX);
        vector<bool> visited(ns, 0);

        dist[i] = 0;
        visited[i] = 1;

        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            i = q.front();
            q.pop();

            // Find all the neighbors of i
            for (int j = 1; j <= 6; j++)
            {
                if (i + j < ns)
                {
                    int next = i + j;
                    pair<int, int> next_cell = decode(i + j, n);
                    if (board[next_cell.first][next_cell.second] != -1)
                    {
                        next = board[next_cell.first][next_cell.second] - 1;
                    }
                    if (!visited[next])
                    {
                        dist[next] = 1 + dist[i];
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        if (dist[ns - 1] == INT_MAX)
            return -1;
        return dist[ns - 1];
    }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    Solution s;
    n = sqrt(n);
    vector<vector<int>> board(n, vector<int>(n, -1));
    for (pair<int, int> p : snakes)
    {
        pair<int, int> cur = s.decode(p.first - 1, n);
        board[cur.first][cur.second] = p.second;
    }
    for (pair<int, int> p : ladders)
    {
        pair<int, int> cur = s.decode(p.first - 1, n);
        board[cur.first][cur.second] = p.second;
    }
    return s.snakesAndLadders(board);
}

int main()
{
    return 0;
}