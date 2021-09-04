#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>> v)
{
    int n = v.size();
    
    unordered_map<int, int> x, y;
    for (int i = 0; i < n; i++)
    {
        x[v[i].first]++;
        y[v[i].second]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += ((x[v[i].first] - 1) * (y[v[i].second] - 1));
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> v1 = {
        {1, 2},
        {2, 0},
        {2, 2},
        {2, 3},
        {4, 2}
    };

    cout<<solve(v1)<<endl;
    return 0;
}