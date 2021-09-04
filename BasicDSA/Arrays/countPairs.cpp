#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> v, int k)
{
    set<int> s(v.begin(), v.end());

    unordered_set<int> u;
    int ctr = 0;
    for (auto x: s)
    {
        if (u.find(x - k) != u.end())
        {
            ctr++;
        }
        u.insert(x);
    }
    return ctr;
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 3};
    cout<<countPairs(v, 1)<<endl;
    return 0;
}