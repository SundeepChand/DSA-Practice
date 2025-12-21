#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<string> &board, int a, int b)
{
    // Check row, col
    for (int i = 0; i < 8; i++)
    {
        if (board[a][i] == 'Q' || board[i][b] == 'Q')
            return false;
    }
    // Check diagonal
    int i = a, j = b;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    i = a, j = b;
    while (i >= 0 && j < 8)
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j++;
    }
    return true;
}

int nPos(vector<string> &board, int a, int n)
{
    if (n <= 0)
        return 1;
    if (a >= 8)
        return 0;
    int ways = 0;
    for (int i = 0; i < 8; i++)
    {
        if (board[a][i] == '.' && canPlace(board, a, i))
        {
            board[a][i] = 'Q';
            ways += nPos(board, a + 1, n - 1);
            board[a][i] = '.';
        }
    }
    return ways;
}

int main()
{
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    cout << nPos(board, 0, 8) << endl;

    return 0;
}