#include <bits/stdc++.h>
using namespace std;

string toString(pair<int, int> p)
{
    return to_string(p.first) + " " + to_string(p.second);
}

int solve(vector<pair<int, int>> v)
{
    int n = v.size();

    unordered_set<string> u;
    for (int i = 0; i < n; i++)
    {
        u.insert(toString(v[i]));
    }

    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> p1 = v[i];
            pair<int, int> p2 = v[j];
            string s1 = toString({p2.first, p1.second});
            string s2 = toString({p1.first, p2.second});
            if (
                u.find(s1) != u.end() &&
                u.find(s2) != u.end() &&
                toString(p1) != s1 &&
                toString(p2) != s1
                // && (p2.first - p1.first) == (p1.second - p2.second)  // Modification for square
            )
            {
                // cout<<toString(p1)<<", "<<toString(p2)<<endl;
                ctr++;
            }
        }
    }
    ctr /= 2;
    return ctr;
}

int main()
{
    vector<pair<int, int>> v1 = {
        {1, 1},
        {0, 1},
        {0, 0},
        {1, 0},
        {2, 1},
        {2, 0},
        {3, 1},
        {3, 0}
    };

    // vector<pair<int, int>> v2 = {
    //     {0,2}, {1,1}, {2, 0}, {0,0}, {2,2}
    // };
    // int n;
    // cin>>n;

    // vector<pair<int, int>> v;
    // for (int i = 0; i < n; i++)
    // {
    //     int x, y;
    //     cin>>x>>y;
    //     v.push_back({x, y});
    // }

    cout<<solve(v1)<<endl;
    return 0;
}