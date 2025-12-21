#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, cur = 0, s1 = 0, s2 = 0;
multiset<ll> m1, m2;
void insert(ll x)
{
    if (m1.empty() || x <= *m1.rbegin())
    {
        m1.insert(x);
        s1 += x;
    }
    else
    {
        m2.insert(x);
        s2 += x;
    }

    cur++;

    if (cur % 2 == 0)
    {
        if (m1.size() > m2.size())
        {
            m2.insert(*m1.rbegin());
            s2 += *m1.rbegin();
            s1 -= *m1.rbegin();
            m1.erase(m1.find(*m1.rbegin()));
        }
        else if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            s1 += *m2.begin();
            s2 -= *m2.begin();
            m2.erase(m2.begin());
        }
    }
    else
    {
        if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            s1 += *m2.begin();
            s2 -= *m2.begin();
            m2.erase(m2.begin());
        }
    }
}

void erase(ll x)
{
    if (x <= *m1.rbegin())
    {
        m1.erase(m1.find(x));
        s1 -= x;
    }
    else
    {
        m2.erase(m2.find(x));
        s2 -= x;
    }

    cur--;

    if (cur % 2 == 0)
    {
        if (m1.size() > m2.size())
        {
            m2.insert(*m1.rbegin());
            s2 += *m1.rbegin();
            s1 -= *m1.rbegin();
            m1.erase(m1.find(*m1.rbegin()));
        }
        else if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            s1 += *m2.begin();
            s2 -= *m2.begin();
            m2.erase(m2.begin());
        }
    }
    else
    {
        if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            s1 += *m2.begin();
            s2 -= *m2.begin();
            m2.erase(m2.begin());
        }
    }
}

double get_median()
{
    if (cur % 2 == 0)
        return (*m1.rbegin() + *m2.begin()) / double(2.0);
    return *m1.rbegin();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n;
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < k; i++)
    {
        insert(v[i]);
    }
    double median = get_median();
    cout << ll((s2 - m2.size() * median) + (m1.size() * median - s1)) << " ";

    for (int i = k; i < n; i++)
    {
        erase(v[i - k]);
        insert(v[i]);
        median = get_median();
        cout << ll((s2 - m2.size() * median) + (m1.size() * median - s1)) << " ";
    }
    cout << endl;

    return 0;
}