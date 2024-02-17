#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

typedef long long ll;
ll cumulativeObservableSum(vector<int> &stockPrice, int k)
{
    map<int, int> mp;
    ll curSum = 0;
    for (int i = 0; i < k; i++)
        mp[stockPrice[i]]++, curSum += stockPrice[i];

    ll ans = -1;
    if (mp.size() == k)
        ans = max(ans, curSum);

    int n = stockPrice.size();
    for (int i = k; i < n; i++)
    {
        mp[stockPrice[i]]++;
        curSum += stockPrice[i];
        mp[stockPrice[i - k]]--;
        curSum -= stockPrice[i - k];
        if (mp[stockPrice[i - k]] == 0)
            mp.erase(stockPrice[i - k]);
        if (mp.size() == k)
            ans = max(ans, curSum);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        cout << cumulativeObservableSum(v, k) << endl;
    }
    return 0;
}