// https://www.hackerrank.com/challenges/a-chessboard-game-1/problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int x, y;
        cin>>x>>y;

        x--;
        y--;

        if (x % 4 <= 1 && y % 4 <= 1)
            cout<<"Second"<<endl;
        else
            cout<<"First"<<endl;
    }
    return 0;
}