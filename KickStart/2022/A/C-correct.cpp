#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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

    int tc = t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool possible = false;

        for (int i = 2; i < n - 2 and !possible; i++)
        {
            bool hasPal = true;
            int j = i - 1, k = i + 1;
            while (j >= 0 and k < n and (k - j) < 5 and (s[j] == '?' or s[k] == '?' or s[j] == s[k]))
            {
                k++, j--;
            }
            hasPal = hasPal or ((k - j) >= 5);

            j = i, k = i + 1;
            while (j >= 0 and k < n and (k - j) < 6 and (s[j] == '?' or s[k] == '?' or s[j] == s[k]))
            {
                k++, j--;
            }
            hasPal = hasPal or ((k - j) >= 6);

            j = i - 1,
            k = i;
            while (j >= 0 and k < n and (k - j) < 6 and (s[j] == '?' or s[k] == '?' or s[j] == s[k]))
            {
                k++, j--;
            }
            hasPal = hasPal or ((k - j) >= 6);
            possible = possible and (!hasPal);
            cout << "DEB: " << i << ", " << hasPal << endl;
        }

        cout << "Case #" << (tc - t) << ": " << (possible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
    return 0;
}