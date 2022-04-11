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

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.length();

        vector<vector<int>> freq(26, vector<int>());
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a'].push_back(i);

        int oddFreqCtr = 0;
        int oddFreqIdx = -1;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i].size() % 2 == 1)
                oddFreqCtr++, oddFreqIdx = i;
        }
        bool canPal = oddFreqCtr < 2;
        if (!canPal)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> front, rear;
        for (int i = 0; i < 26; i++)
        {
            if (i != oddFreqIdx)
            {
                int j = 0, k = freq[i].size() - 1;
                while (j < k)
                {
                    front.push_back(freq[i][j] + 1);
                    rear.push_back(freq[i][k] + 1);
                    j++, k--;
                }
            }
        }
        for (int i = 0; i < front.size(); i++)
            cout << front[i] << " ";
        if (oddFreqIdx != -1)
        {
            for (int i = 0; i < freq[oddFreqIdx].size(); i++)
                cout << (freq[oddFreqIdx][i] + 1) << " ";
        }
        for (int i = rear.size() - 1; i >= 0; i--)
            cout << rear[i] << " ";
        cout << endl;
    }
    return 0;
}