// https://leetcode.com/discuss/post/5442458/google-l4-hyderabad-telephonic-screening-eztk/
#include <bits/stdc++.h>
using namespace std;

uint32_t ipToInt(const string &ip)
{
    uint32_t res = 0;
    int curVal = 0, curToken = 3;
    for (char c : ip)
    {
        if (c == '.')
        {
            int shift = 8 * curToken;
            res = (res | (curVal << shift));

            curToken--;
            curVal = 0;
            continue;
        }
        curVal = 10 * curVal + (c - '0');
    }

    // curToken becomes 0, hence shift is 0
    res = (res | curVal);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<uint32_t, pair<bool, string>>> ipRanges;

    while (n--)
    {
        string lr, ur, country;

        cin >> lr >> ur >> country;

        ipRanges.push_back({ipToInt(lr), {0, country}});
        ipRanges.push_back({ipToInt(ur), {1, country}});
    }

    sort(ipRanges.begin(), ipRanges.end());

    int q;
    cin >> q;

    while (q--)
    {
        string ip;
        cin >> ip;

        uint32_t ipCode = ipToInt(ip);

        string maxStr = "";
        maxStr += char(127);
        auto it = upper_bound(ipRanges.begin(), ipRanges.end(), make_pair(ipCode, make_pair(0, maxStr)));

        if (it == ipRanges.end() or it->second.first == 0)
        {
            cout << "NA";
        }
        else
        {
            cout << (it->second.second);
        }
        cout << endl;
    }
    return 0;
}