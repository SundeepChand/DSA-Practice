#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

string removeDuplicateLetters(string s)
{
    // Stores the frequency of characters
    int cnt[26] = {0};

    // Mark visited characters
    int vis[26] = {0};

    int n = s.size();

    // Stores count of each character
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    // Stores the resultant string
    string res = "";

    for (int i = 0; i < n; i++)
    {

        // Decrease the count of
        // current character
        cnt[s[i] - 'a']--;

        // If character is not already
        // in answer
        if (!vis[s[i] - 'a'])
        {

            // Last character > S[i]
            // and its count > 0
            while (res.size() > 0 && res.back() < s[i] && cnt[res.back() - 'a'] > 0)
            {

                // Mark letter unvisited
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }

            // Add s[i] in res and
            // mark it visited
            res += s[i];
            vis[s[i] - 'a'] = 1;
        }
    }

    // Return the resultant string
    return res;
}

int maximizeTransactions(vector<int> &t)
{
    int n = t.size();

    priority_queue<int> pq;
    int tot = 0, ctr = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] >= 0)
            tot += t[i], ctr++;
        else
        {

            if (t[i] + tot >= 0)
            {
                ctr++;
                tot += t[i];
            }
            if (pq.size() > 0 and -t[i] < pq.top())
            {
            }
        }
    }
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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
    }
    return 0;
}