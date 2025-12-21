#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

#define all(x) (x).begin(), (x).end()

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
        int n, m, k;
        cin >> n >> m >> k;

        string a, b;
        cin >> a >> b;

        sort(all(a));
        sort(all(b));

        string c = "";
        int i = 0, j = 0, flag = 0;
        while (i < n and j < m)
        {
            if (a[i] < b[j])
            {
                if (flag <= 0 and -flag < k)
                {
                    c += a[i++];
                    flag--;
                }
                else if (flag < 0 and -flag >= k)
                {
                    c += b[j++];
                    flag = 1;
                }
                else
                {
                    c += a[i++];
                    flag = -1;
                }
            }
            else if (a[i] > b[j])
            {
                if (flag >= 0 and flag < k)
                {
                    c += b[j++];
                    flag++;
                }
                else if (flag > 0 and flag >= k)
                {
                    c += a[i++];
                    flag = -1;
                }
                else
                {
                    c += b[j++];
                    flag = 1;
                }
            }
            else
            {
                if (flag == 0)
                {
                    c += a[i++];
                    flag--;
                }
                else if (flag > 0)
                {
                    c += a[i++];
                    flag = 0;
                }
                else
                {
                    c += b[j++];
                    flag = 0;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}