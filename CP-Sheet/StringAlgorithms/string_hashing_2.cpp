#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void solveEasyVersion(string &s)
{
    int n = s.size();

    /*
    i/p: abcdfdcecba
    o/p: abcdfdcba

    s[]:  a  b  c  d  f  d  c  e  c  b  a

    pref[i] = hash(s[0..i])
    suf[i] = hash(s[i..n - 1])

    pref_b[i] = hash(rev(s[0..i]))
    suf_b[i] = hash(rev(s[i..n - 1]))

    H(i, j) = pref[i] * pow(p)

    TC: O(n^2)
    SC: O(n)

    */

    int ans = 1, pref_len = 1, suf_len = 0;

    // int p1 = 31, m1 = 1e9 + 9, p2 = 29, m2 = 1e9 + 7;
    int p = 31, m = 1e9 + 9;
    int pow_p = p;

    vector<int> pref(n), suf(n), pref_b(n), suf_b(n);

    pref[0] = pref_b[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; i++)
    {
        pref[i] = ((pref[i - 1] * p) % m + (s[i] - 'a' + 1)) % m;
        pref_b[i] = (((s[i] - 'a' + 1) * pow_p) % m + pref_b[i - 1]) % m;
        pow_p = (pow_p * p) % m;
        if (pref[i] == pref_b[i] and i + 1 > ans)
            ans = i + 1, pref_len = i + 1;
    }

    suf[n - 1] = suf_b[n - 1] = (s[n - 1] - 'a' + 1);
    pow_p = p;
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = ((pow_p * (s[i] - 'a' + 1)) % m + suf[i + 1]) % m;
        pow_p = (pow_p * p) % m;

        suf_b[i] = ((suf_b[i + 1] * p) % m + (s[i] - 'a' + 1)) % m;

        if (suf[i] == suf_b[i] and n - i > ans)
        {
            ans = n - i, pref_len = 0, suf_len = n - i;
        }
    }

    int pow_p2 = p;
    for (int i = 0; i < n; i++)
    {
        int pow_p1 = p;
        for (int j = n - 1; j > i; j--)
        {
            int forward_hash = ((pref[i] * pow_p1) % m + suf[j]) % m;
            int backward_hash = ((suf_b[j] * pow_p2) % m + pref_b[i]) % m;
            pow_p1 = (pow_p1 * p) % m;
            // cerr << "i = " << i << " j = " << j << " : " << forward_hash << " " << backward_hash << endl;

            if (forward_hash == backward_hash and i + 1 + n - j > ans)
            {
                ans = i + 1 + n - j;
                pref_len = i + 1, suf_len = n - j;
            }
        }
        pow_p2 = (pow_p2 * p) % m;
    }

    // for (int x : pref)
    //     cerr << x << " ";
    // cerr << endl;

    // for (int x : pref_b)
    //     cerr << x << " ";
    // cerr << endl;

    // for (int x : suf)
    //     cerr << x << " ";
    // cerr << endl;

    // for (int x : suf_b)
    //     cerr << x << " ";
    // cerr << endl;

    // cerr << ans << " " << pref_len << " " << suf_len << endl;

    cout << (s.substr(0, pref_len) + s.substr(n - suf_len)) << endl;
}

void solveHardVersion(const string &s)
{
    int n = s.size();

    int i = 0, j = n - 1;
    while (i < j and s[i] == s[j])
        i++, j--;

    if (i >= j)
    {
        cout << s << endl;
        return;
    }

    int lb = i, ub = j;

    int ans = 2 * i + 1, pref_len = i + 1, suf_len = i;

    int p1 = 31, m1 = 1e9 + 9, p2 = 47, m2 = 1e9 + 9;

    vector<pair<int, int>> pref(n, {0, 0}), pref_b(n, {0, 0}), suf(n, {0, 0}), suf_b(n, {0, 0});

    pref[lb] = pref_b[lb] = {s[lb] - 'a' + 1, s[lb] - 'a' + 1};
    int pow_p1 = p1, pow_p2 = p2;
    for (i = lb + 1; i <= ub; i++)
    {
        int curVal = s[i] - 'a' + 1;
        pref[i] = {
            ((pref[i - 1].first * p1) % m1 + curVal) % m1,
            ((pref[i - 1].second * p2) % m2 + curVal) % m2};

        pref_b[i] = {
            ((curVal * pow_p1) % m1 + pref_b[i - 1].first) % m1,
            ((curVal * pow_p2) % m2 + pref_b[i - 1].second) % m2};
        pow_p1 = (pow_p1 * p1) % m1, pow_p2 = (pow_p2 * p2) % m2;

        if (pref[i] == pref_b[i] and i + 1 + n - 1 - ub > ans)
        {
            ans = i + 1 + n - 1 - ub;
            pref_len = i + 1, suf_len = n - 1 - ub;
        }
    }

    suf[ub] = suf_b[ub] = {s[ub] - 'a' + 1, s[ub] - 'a' + 1};
    pow_p1 = p1, pow_p2 = p2;
    for (j = ub - 1; j >= lb; j--)
    {
        int curVal = s[j] - 'a' + 1;
        suf[j] = {
            ((curVal * pow_p1) % m1 + suf[j + 1].first) % m1,
            ((curVal * pow_p2) % m2 + suf[j + 1].second) % m2};
        pow_p1 = (pow_p1 * p1) % m1, pow_p2 = (pow_p2 * p2) % m2;

        suf_b[j] = {
            ((suf_b[j + 1].first * p1) % m1 + curVal) % m1,
            ((suf_b[j + 1].second * p2) % m2 + curVal) % m2};

        if (suf[j] == suf_b[j] and lb + n - j > ans)
        {
            ans = lb + n - j;
            pref_len = lb, suf_len = n - j;
        }
    }

    // for (int x : pref)
    //     cerr << x << " ";
    // cerr << endl;

    // for (int x : pref_b)
    //     cerr << x << " ";
    // cerr << endl;

    // for (int x : suf)
    //     cerr << x << " ";
    // cerr << endl;

    // for (int x : suf_b)
    //     cerr << x << " ";
    // cerr << endl;

    // cerr << ans << " " << pref_len << " " << suf_len << endl;
    cout << (s.substr(0, pref_len) + s.substr(n - suf_len)) << endl;
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
        string s;
        cin >> s;
        solveHardVersion(s);
    }
    return 0;
}