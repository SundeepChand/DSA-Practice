// https://www.hackerrank.com/challenges/nimble-game-1/problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;

        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;

            if (x % 2 == 1)
                xr ^= i;
        }
        if (xr == 0)
            cout<<"Second";
        else
            cout<<"First";
        cout<<endl;
    }
    return 0;
}