// https://www.hackerrank.com/challenges/tower-breakers-1/problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n, m;
        cin>>n>>m;

        if (n % 2 == 0 || m == 1)
            cout<<2;
        else
            cout<<1;
        cout<<endl;
    }
    return 0;
}