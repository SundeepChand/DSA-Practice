#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool poss = false;

bool isPal(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

bool checkValid(const string &s)
{
    int n = s.length();
    for (int i = 5; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            if (isPal(s.substr(j, i)))
                return false;
        }
    }
    return true;
}

void replaceQuestionMarks(string &s, int i)
{
    if (poss)
        return;
    int n = s.length();
    // cout<<"DEB: "<<i<<endl;
    if (i >= n / 2)
    {
        if (s[i] == '?')
        {
            s[i] = '0';
            poss = poss || checkValid(s);
            s[i] = '1';
            poss = poss || checkValid(s);
            s[i] = '?';
        }
        else
        {
            poss = poss || checkValid(s);
        }
        return;
    }
    if (s[i] == '0' && s[n - i - 1] == '?')
    {
        s[n - i - 1] = '1';
        replaceQuestionMarks(s, i + 1);
        s[n - i - 1] = '?';
    }
    else if (s[i] == '1' && s[n - i - 1] == '?')
    {
        s[n - i - 1] = '0';
        replaceQuestionMarks(s, i + 1);
        s[n - i - 1] = '?';
    }
    else if (s[i] == '?' && s[n - i - 1] == '0')
    {
        s[i] = '1';
        replaceQuestionMarks(s, i + 1);
        s[i] = '?';
    }
    else if (s[i] == '?' && s[n - i - 1] == '1')
    {
        s[i] = '0';
        replaceQuestionMarks(s, i + 1);
        s[i] = '?';
    }
    else if (s[i] == '?' && s[n - i - 1] == '?')
    {
        s[i] = '0', s[n - i - 1] = '1';
        replaceQuestionMarks(s, i + 1);
        s[i] = '1', s[n - i - 1] = '0';
        replaceQuestionMarks(s, i + 1);
        s[i] = '?', s[n - i - 1] = '?';
    }
    else
        replaceQuestionMarks(s, i + 1);
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

    int tc = t;

    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        poss = false;
        replaceQuestionMarks(s, 0);

        cout<<"Case #"<<(tc - t)<<": ";
        if (poss)
        {
            cout<<"POSSIBLE";
        }
        else
            cout<<"IMPOSSIBLE";
        cout<<endl;
    }
    return 0;
}