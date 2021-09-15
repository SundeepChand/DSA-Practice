/*
Given a subtraction game, played by removing k elements from a set,
where, k belongs to the set s. Find the grundy values for each position n.
*/
#include <bits/stdc++.h>
using namespace std;

int mex(unordered_set<int> vals)
{
    for (int i = 0; true; i++)
    {
        if (vals.find(i) == vals.end())
            return i;
    }
    return -1;
}

int main()
{
    vector<int> sub {1, 4, 3};

    int n;
    cin>>n;

    vector<int> grundy(n);
    grundy[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        unordered_set<int> followers;
        for (int j = 0; j < sub.size(); j++)
        {
            if (i >= sub[j])
                followers.insert(grundy[i - sub[j]]);
        }
        grundy[i] = mex(followers);
    }

    cout<<"Grundy values for n = "<<n<<endl;
    for (auto x: grundy)
        cout<<x<<", ";
    return 0;
}