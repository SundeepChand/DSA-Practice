#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool updateCurTime(vector<vector<int>> &v, int i, int j, int &curTime)
{
    if (curTime < v[i][j])
    {
        curTime = v[i][j] + 1;
        return false;
    }
    else
        curTime++;
    return true;
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
        int m;
        cin >> m;

        vector<vector<int>> v(2, vector<int>(m));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        }

        int minTime = INT_MAX, curTime = 0;
        for (int i = 1; i < m; i++)
        {
            updateCurTime(v, 0, i, curTime);
        }
        updateCurTime(v, 1, m - 1, curTime);

        for (int i = m - 2; i >= 0; i--)
        {
            updateCurTime(v, 1, i, curTime);
        }
        minTime = min(minTime, curTime);

        curTime = 0;
        updateCurTime(v, 1, 0, curTime);
        for (int i = 0; i < m - 1; i++)
        {
            if (i % 2 == 0)
            {
                updateCurTime(v, 1, i + 1, curTime);
                updateCurTime(v, 0, i + 1, curTime);
            }
            else
            {
                updateCurTime(v, 0, i + 1, curTime);
                updateCurTime(v, 1, i + 1, curTime);
            }
        }
        minTime = min(minTime, curTime);

        cout << minTime << endl;
    }
    return 0;
}