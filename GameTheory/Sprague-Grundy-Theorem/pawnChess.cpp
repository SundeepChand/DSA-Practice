#include<bits/stdc++.h>
using namespace std;

string solve(string board){
    int n = board.size();
    
    vector<int> pos;
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        if (board[i] == 'P')
        {
            pos.push_back(i);
            pos[pos.size() - 1] -= (pos.size() - 1);
            xr = xr ^ pos[pos.size() - 1];
        }
    }
    if (xr == 0)
        return "No";
    return "Yes";
}

int main()
{
    return 0;
}