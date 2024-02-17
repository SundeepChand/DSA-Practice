#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

pair<int, int> getSwapIdx(vector<int> v)
{
    int n = v.size();
    pair<int, int> idx = {0, 0};
    if (n == 1)
        return idx;

    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            if (flag == 0)
            {
                idx.first = i - 1, idx.second = i, flag = 1;
            }
            else if (flag == 1)
            {
                idx.second = i, flag = 2;
            }
            else if (flag == 2)
                return {-1, -1};
        }
    }

    if (flag)
    {
        int prev = v[idx.second];
        while (idx.second < n and v[idx.second] == prev)
            (idx.second)++;
        (idx.second)--;

        prev = v[idx.first];
        while (idx.first >= 0 and v[idx.first] == prev)
            (idx.first)--;
        (idx.first)++;
    }

    swap(v[idx.first], v[idx.second]);

    int maxVal = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v[i] < maxVal)
            return {-1, -1};
        maxVal = v[i];
    }

    return idx;
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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v1(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v1[i][j];
            }
        }

        bool ans = true;
        pair<int, int> idx = {0, 0};
        for (int i = 0; i < n; i++)
        {
            idx = getSwapIdx(v1[i]);
            if (idx != make_pair(0LL, 0LL))
                break;
        }

        cerr << idx.first << " " << idx.second << endl;
        if (idx.first == -1 or idx.second == -1)
        {
            ans = false;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                swap(v1[i][idx.first], v1[i][idx.second]);
                int maxVal = v1[i][0];
                for (int j = 0; j < m; j++)
                {
                    if (v1[i][j] < maxVal)
                    {
                        ans = false;
                        break;
                    }
                    maxVal = v1[i][j];
                }
            }
        }

        if (ans)
            cout << (idx.first + 1) << " " << (idx.second + 1);
        else
            cout << (-1);
        cout << endl;
    }
    return 0;
}