#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &grid, string &s, int i, int j, int k, char prev = 'N')
{
    // for (string t : grid)
    // {
    //     cout << t << endl;
    // }
    // cout << "-------- " << s[k] << endl;

    if (k == 48 && i == 6 && j == 0)
        return 1;
    if (i == 6 && j == 0)
        return 0;
    if (k == 48)
        return 0;

    // Try to prune the search tree
    if (
        prev == 'U' &&
        (i == 0 || (i > 0 && grid[i - 1][j] == '*')) &&
        (j > 0 && grid[i][j - 1] == '.') &&
        (j < 6 && grid[i][j + 1] == '.'))
        return 0;
    else if (prev == 'D' &&
             (i == 6 || (i < 6 && grid[i + 1][j] == '*')) &&
             (j > 0 && grid[i][j - 1] == '.') &&
             (j < 6 && grid[i][j + 1] == '.'))
        return 0;
    else if (prev == 'L' &&
             (j == 0 || (j > 0 && grid[i][j - 1] == '*')) &&
             (i > 0 && grid[i - 1][j] == '.') &&
             (i < 6 && grid[i + 1][j] == '.'))
        return 0;
    else if (prev == 'R' &&
             (j == 6 || (j < 6 && grid[i][j + 1] == '*')) &&
             (i > 0 && grid[i - 1][j] == '.') &&
             (i < 6 && grid[i + 1][j] == '.'))
        return 0;

    int ctr = 0;
    grid[i][j] = '*';
    if ((s[k] == '?' || s[k] == 'U') && i > 0 && grid[i - 1][j] == '.')
        ctr += solve(grid, s, i - 1, j, k + 1, 'U');
    if ((s[k] == '?' || s[k] == 'L') && j > 0 && grid[i][j - 1] == '.')
        ctr += solve(grid, s, i, j - 1, k + 1, 'L');
    if ((s[k] == '?' || s[k] == 'D') && i < 6 && grid[i + 1][j] == '.')
        ctr += solve(grid, s, i + 1, j, k + 1, 'D');
    if ((s[k] == '?' || s[k] == 'R') && j < 6 && grid[i][j + 1] == '.')
        ctr += solve(grid, s, i, j + 1, k + 1, 'R');
    grid[i][j] = '.';
    return ctr;
}

/*

????????????????????????????????????????????????

*/

int main()
{
    string s;
    cin >> s;

    vector<string> grid = {
        ".......",
        ".......",
        ".......",
        ".......",
        ".......",
        ".......",
        "......."};

    cout << solve(grid, s, 0, 0, 0) << endl;

    return 0;
}