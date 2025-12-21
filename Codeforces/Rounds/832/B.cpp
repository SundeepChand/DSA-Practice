#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
B A N B A N B A N  B  A  N  B  A  N

*/

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
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else if (n == 2)
        {
            cout << 1 << endl;
            cout << 2 << " " << 6 << endl;
        }
        else
        {
            vector<pair<int, int>> ans;
            int j = 3 * n;
            for (int i = 2; i < j; i += 3, j -= 3)
            {
                if (j % 3 == 2)
                    j--;
                ans.push_back({i, j});
            }

            cout << ans.size() << endl;
            for (auto x : ans)
                cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}