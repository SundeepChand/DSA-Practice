#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define BASE 26
#define START 'a'

int addMod(ll a, ll b, int m)
{
    return (a + b) % m;
}

int diffMod(ll a, ll b, int m)
{
    return addMod(m, (a - b), m) % m;
}

int multMod(ll a, ll b, int m)
{
    return (a * b) % m;
}

int powMod(int a, int b, int m)
{
    int ans = 1, cur = a;
    while (b)
    {
        if (b & 1)
            ans = multMod(ans, cur, m);
        cur = multMod(cur, cur, m);
        b >>= 1;
    }
    return ans;
}

int computeHash(int prev, char first, char cur, int m)
{
    first -= START, cur -= START;
    return addMod(
        cur,
        multMod(
            diffMod(
                prev,
                multMod(
                    (int)first,
                    powMod(BASE, m - 1, MOD),
                    MOD),
                MOD),
            BASE,
            MOD),
        MOD);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string text, pattern;
    cin >> text;
    cin >> pattern;

    int n = text.size(), m = pattern.size();

    // Pre-compute the hash values.
    int patHash = 0;
    for (char c : pattern)
    {
        patHash = addMod(c - START, multMod(patHash, BASE, MOD), MOD);
    }

    vector<int> hash(n - m + 1);

    hash[0] = 0;
    for (int i = 0; i < m; i++)
    {
        hash[0] = addMod(
            text[i] - START,
            multMod(hash[0], BASE, MOD),
            MOD);
    }

    for (int i = 1; i < n - m + 1; i++)
    {
        hash[i] = computeHash(hash[i - 1], text[i - 1], text[i + m - 1], m);
    }

    // Perform string matching.
    for (int i = 0; i < hash.size(); i++)
    {
        if (hash[i] == patHash and text.substr(i, m) == pattern)
            cout << "Found at " << i << endl;
    }

    return 0;
}