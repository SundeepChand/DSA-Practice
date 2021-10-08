#include <bits/stdc++.h>
using namespace std;

int main()
{
    // The approach here is to maintain a set of the intervals. Whenever a new traffic light is
    // added, then we find the interval to which it belongs to, and split it accordingly. And based
    // on that we maintain a set of lengths of the intervals and then print the maximum of them.
    int n, x;
    cin >> x >> n;

    vector<int> v(n);
    set<pair<int, int>> s;
    map<int, int> len;

    s.insert({1, x});
    len[x] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        auto it = s.upper_bound({v[i], INT_MAX});
        it--;

        if (v[i] != it->second)
        {
            pair<int, int> p = *it;
            s.erase(it);
            len[p.second - p.first + 1]--;
            if (len[p.second - p.first + 1] == 0)
                len.erase(p.second - p.first + 1);

            s.insert({p.first, v[i]});
            len[v[i] - p.first + 1]++;

            s.insert({v[i] + 1, p.second});
            len[p.second - v[i]]++;
        }
        auto ans = len.end();
        ans--;
        cout << (ans->first) << " ";
    }
    cout << "\n";
    return 0;
}

/*
int main()
{
    ios_base::sync_with_stdio(0); // This soln. exceeds time limit without Fast IO
    cin.tie(0);

    int n, x;
    cin >> x >> n;

    vector<int> v(n);
    set<pair<int, int>> s;
    multiset<int> len;

    s.insert({1, x});
    len.insert(x);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        auto it = s.upper_bound({v[i], INT_MAX});
        it--;
        if (v[i] != it->second)
        {
            pair<int, int> p = *it;
            s.erase(it);
            len.erase(len.find(p.second - p.first + 1));

            s.insert({p.first, v[i]});
            len.insert(v[i] - p.first + 1);

            s.insert({v[i] + 1, p.second});
            len.insert(p.second - v[i]);
        }
        auto ans = len.end();
        ans--;
        cout << (*ans) << " ";
    }
    cout << "\n";
    return 0;
}
*/

/*
int32_t main()
{
    // A much better soln. Here instead of storing the intervals, we simply put the points into a
    // set and find the intervals directly, by finding two consecutive elements. This works because
    // the intervals are continuous and non-overlapping.
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<int> s;
    int x, n;
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    multiset<int> dis;
    dis.insert(x);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto it = s.upper_bound(p);
        int a = *it;
        --it;
        int b = *it;
        dis.erase(dis.find(a - b));
        s.insert(p);
        dis.insert(a - p);
        dis.insert(p - b);
        cout << *dis.rbegin() << ' ';
    }

    return 0;
}
*/