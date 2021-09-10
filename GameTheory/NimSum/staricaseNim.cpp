#include<bits/stdc++.h>
using namespace std;

// Checkout this for the theory: https://codeforces.com/blog/entry/44651
// So we need to consider the xor of the odd positions, in order to
// determine the winning or losing positions.
string solve(vector<int> balls)
{
    int n = balls.size();
    int xr = 0;
    for (int i = 1; i < n; i += 2)
        xr ^= balls[i];
    if (xr == 0)
        return "second";
    return "first";
}

int main()
{
    vector<int> balls {2, 3, 1, 2, 0, 3};

    cout<<solve(balls)<<endl;
}