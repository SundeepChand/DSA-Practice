#include <bits/stdc++.h>
using namespace std;

multiset<int> m1, m2;
int k, cur = 0;
void insert(int x)
{
    if (m1.empty() || x <= *m1.rbegin())
        m1.insert(x);
    else
        m2.insert(x);

    cur++;

    if (cur % 2 == 0)
    {
        if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            m2.erase(m2.begin());
        }
        else if (m1.size() > m2.size())
        {
            m2.insert(*m1.rbegin());
            m1.erase(m1.find(*m1.rbegin()));
        }
    }
    else
    {
        if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            m2.erase(m2.begin());
        }
    }
}

void erase(int x)
{
    if (x <= *m1.rbegin())
        m1.erase(m1.find(x));
    else
        m2.erase(m2.find(x));

    cur--;

    if (cur % 2 == 0)
    {
        if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            m2.erase(m2.begin());
        }
        else if (m1.size() > m2.size())
        {
            m2.insert(*m1.rbegin());
            m1.erase(m1.find(*m1.rbegin()));
        }
    }
    else
    {
        if (m1.size() < m2.size())
        {
            m1.insert(*m2.begin());
            m2.erase(m2.begin());
        }
    }
}

void print_median()
{
    cout << *m1.rbegin() << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < k; i++)
    {
        insert(v[i]);
    }
    print_median();
    for (int i = k; i < n; i++)
    {
        erase(v[i - k]);
        insert(v[i]);
        print_median();
    }
    cout << endl;

    return 0;
}