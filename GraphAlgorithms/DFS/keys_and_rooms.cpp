#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (auto x : rooms[cur])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }

        bool ans = true;
        for (bool x : visited)
            ans = ans && x;
        return ans;
    }
};

int main()
{
    return 0;
}