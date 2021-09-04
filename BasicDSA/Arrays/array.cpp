#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;

typedef long long ll;
ll ans = INT_MIN;
void solve(vector<int> &path, int i, int maxStep, int sum)
{
    int n = path.size();
    if (i >= n - 1)
    {
        if (sum > ans)
            ans = sum;
        return;
    }
    for (int j = i + 1; j <= i + maxStep && j < n; j++)
    {
        solve(path, j, maxStep, sum + path[j]);
    }
}
ll journey(vector<int> path, int maxStep)
{
    solve(path, 0, maxStep, path[0]);
    return ans;
}

int main()
{
    vector<int> v = {10, -20, -5};
    cout<<journey(v, 2)<<endl;
    return 0;
}