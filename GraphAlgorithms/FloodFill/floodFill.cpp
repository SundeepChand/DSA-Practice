#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int color = image[sr][sc];
        if (color == newColor)
            return image;

        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int r = cur.first, c = cur.second;
            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == color)
                {
                    q.push({nr, nc});
                    image[nr][nc] = newColor;
                }
            }
        }
        return image;
    }
};