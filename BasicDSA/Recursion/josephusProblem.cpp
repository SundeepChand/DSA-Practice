// https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int k, int idx)
{
    if (v.size() == 1)
        return v[0];
    int kill_idx = (idx + k) % v.size();
    v.erase(v.begin() + kill_idx);
    return solve(v, k, kill_idx);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;

    k--;

    cout << solve(v, k, 0) << endl;
    return 0;
}