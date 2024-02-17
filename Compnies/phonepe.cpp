#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXK = 100005;

int n, q, t;
string s;
int magic[MAXN][20];

void precompute()
{
    for (int i = 0; i < n; i++)
    {
        magic[i][0] = 0;
        for (int j = 1; j <= 18; j++)
        {
            cerr << "Here " << i << " " << j << endl;
            if (i < j)
                magic[i][j] = -1;
            else
            {
                int len = magic[i - j][j - 1];
                while (len >= 0 && s[i - len] != s[i - j - len])
                    len = magic[i - j + len][min(len, j - 1)];
                magic[i][j] = len + 1;
            }
        }
    }
}

int count_magical(int i, int len)
{
    int cnt = 0;
    for (int j = 1; j <= 18; j++)
    {
        if (i - j + 1 < len)
            break;
        if (magic[i - j + 1][j] >= len)
            cnt++;
    }
    return cnt;
}

int kth_shortest_magical(int i, int k)
{
    int lo = 1, hi = i, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (count_magical(i, mid) >= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> q >> s;
        precompute();
        cout << "Test Case #" << tc << ":\n";
        while (q--)
        {
            int i, k;
            cin >> i >> k;
            int ans = kth_shortest_magical(i - 1, k);
            cout << ans << "\n";
        }
    }
    return 0;
}
