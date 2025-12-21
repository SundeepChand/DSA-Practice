#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int grid[1001][1001];

int n, m, q, countries = 0;

void destroyCountry(int x, int y)
{
    if (grid[x][y] == 0)
        return;

    int dest = 1;

    queue<vector<int>> q;
    q.push({x, y});
    grid[x][y] = 0;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        int i = front[0], j = front[1];
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 and nj >= 0 and ni < n and nj < m and grid[ni][nj] == 1)
            {
                q.push({ni, nj});
                grid[ni][nj] = 0;
                dest++;
            }
        }
    }
    countries -= dest;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            countries += grid[i][j];
        }
    }

    auto start = high_resolution_clock::now();
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        destroyCountry(x, y);
        cout << countries << '\n';
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Took " << duration.count() << " ms" << '\n';

    return 0;
}