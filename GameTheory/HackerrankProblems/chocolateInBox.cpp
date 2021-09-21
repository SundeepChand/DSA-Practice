// https://www.hackerrank.com/challenges/chocolate-in-box/problem
#include <bits/stdc++.h>
using namespace std;

/*
The game presented is a standard nim game.
And the solution here is to find the number of ways to reach nim-sum of 0 from the initial state.
So basically the approach is to find all the array elements which are less than themselves, when
XORed with the total nim-sum.
*/
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        xr ^= v[i];
    }

    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] ^ xr) < v[i])
            ctr++;
    }
    cout << ctr << endl;
    return 0;
}