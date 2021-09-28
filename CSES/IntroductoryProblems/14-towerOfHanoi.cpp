#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n, int s, int e, int a)
{
    vector<vector<int>> res;
    if (n <= 1)
    {
        res.push_back({s, e});
        return res;
    }
    vector<vector<int>> v1 = solve(n - 1, s, a, e);
    vector<vector<int>> v2 = solve(n - 1, a, e, s);
    res.insert(res.end(), v1.begin(), v1.end());
    res.insert(res.end(), {s, e});
    res.insert(res.end(), v2.begin(), v2.end());
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> moves = solve(n, 1, 3, 2);
    cout << moves.size() << endl;
    for (int i = 0; i < moves.size(); i++)
    {
        cout << moves[i][0] << " " << moves[i][1] << endl;
    }
    return 0;
}