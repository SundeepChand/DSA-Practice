// https://www.hackerrank.com/challenges/misere-nim-1/problem
// See here for an explanation: https://www.cs.cmu.edu/afs/cs/academic/class/15859-f01/www/notes/comb.pdf
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
        bool all_ones = true;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            xr = xr ^ x;
            if (x > 1)
                all_ones = false;
        }
        if (all_ones)
        {
            if (n % 2 == 0)
                cout<<"First";
            else
                cout<<"Second";
        }
        else
        {
            if (xr == 0)
                cout<<"Second";
            else
                cout<<"First";
        }
        cout<<endl;
    }
    return 0;
}