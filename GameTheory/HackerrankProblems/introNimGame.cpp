// https://www.hackerrank.com/challenges/nim-game-1/problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int g;
    cin>>g;

    while (g--)
    {
        int n;
        cin>>n;

        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            xr ^= x;
        }

        if (xr == 0)
            cout<<"Second";
        else
            cout<<"First";
        cout<<endl;
    }
    return 0;
}