// https://www.hackerrank.com/challenges/poker-nim-1/problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n, k;
        cin>>n>>k;

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