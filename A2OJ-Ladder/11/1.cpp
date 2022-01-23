#include <bits/stdc++.h>
using namespace std;

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

string minimumPossibleN(int f, int k)
{
}

vector<int> makeSandwiches(int b, int e)
{
    int x = b - 2 * e;
    if (x % 2 == 1 || x < 0)
        return vector<int>();
    x /= 2;
    int y = e - x;
    if (y < 0)
        return vector<int>();
    return vector<int>({x, y});
}

int MOD = 1000000009;
int solve(vector<int> &cards, int k)
{
    int n = cards.size();

    int sum = 0;
    for (auto &x : cards)
    {
        x = x % k;
        if (x < 0)
            x += k;
        sum += x;
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0]++;

    for (int i = 1; i <= n; i++)
    {

        dp[i][cards[i - 1]]++;
        for (int j = 1; j <= sum; j++)
        {

            if (dp[i - 1][j] > 0)
            {
                dp[i][j]++;
                dp[i][j + cards[i - 1]]++;
            }
        }
    }

    int count = 0;
    for (int j = 1; j <= sum; j++)
        if (dp[n][j] > 0)
            if (j % k == 0)
                count = (count + dp[n][j]) % MOD;

    return count;
}

vector<int> winOverDemon(vector<int> cards, vector<int> queries)
{
    vector<int> ans;
    for (int x : queries)
    {
        ans.push_back(solve(cards, x) + 1);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> q = {9};
    vector<int> ans = winOverDemon(v, q);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}