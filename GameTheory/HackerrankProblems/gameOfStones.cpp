// https://www.hackerrank.com/challenges/game-of-stones-1/problem
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

        if (n % 7 <= 1)
            cout<<"Second";
        else
            cout<<"First";
        cout<<endl;
    }
    return 0;
}