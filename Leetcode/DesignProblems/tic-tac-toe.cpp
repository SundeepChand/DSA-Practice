// The problem is to design a tic-tac-toe
#include <bits/stdc++.h>
using namespace std;

/*
Questions to ask for:

1) Is the game timed?
2) Is undo feature available?
3) Is there spectate feature?
4) Are there game statistics?
5) Is there AI option?

Pick a subset of the features you would like to work on
 */

#define EXIT_GAME 2

class Player
{
private:
    char side;

public:
    Player(char side)
    {
        this->side = side;
    }

    char getSide()
    {
        return side;
    }
};

class Board
{
private:
    int n, spacesEmpty;
    vector<vector<char>> board;

public:
    Board(int n = 3)
    {
        this->n = n;
        board = vector<vector<char>>(n, vector<char>(n, ' '));
        spacesEmpty = n * n;
    }

    void displayBoard()
    {
        for (int i = 0; i < n; i++)
        {
            cout << " ";
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j];
                if (j < n - 1)
                    cout << " | ";
            }
            cout << endl;
            if (i < n - 1)
            {
                for (int j = 0; j < 3 * n; j++)
                    cout << "-";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }

    int checkWinner()
    {
        // Returns -1 if draw, 0 if undecided, 1 if X wins, 2 if O wins

        for (int i = 0; i < n; i++)
        {
            // Check row-wise
            char cur = board[i][0];
            if (cur == ' ')
                continue;
            int j = 1;
            while (j < n && board[i][j] == cur)
                j++;
            if (j == n)
                return cur == 'X' ? 1 : 2;

            // Check col-wise
            cur = board[0][i];
            if (cur == ' ')
                continue;
            j = 1;
            while (j < n && board[j][i] == cur)
                j++;
            if (j == n)
                return cur == 'X' ? 1 : 2;
        }

        // Check principal diagonal
        if (board[0][0] != ' ')
        {
            char cur = board[0][0];
            int i = 1, j = 1;
            while (i < n && board[i][j] == cur)
                i++, j++;
            if (i == n && j == n)
                return cur == 'X' ? 1 : 2;
        }

        // Check auxiliary diagonal
        if (board[0][n - 1] != ' ')
        {
            char cur = board[0][n - 1];
            int i = 1, j = n - 2;
            while (i < n && board[i][j] == cur)
                i++, j--;
            if (i == n && j == -1)
                return cur == 'X' ? 1 : 2;
        }
        return spacesEmpty <= 0 ? -1 : 0;
    }

    int makeMove(int i, int j, Player p)
    {
        // Returns 0 on successfully placing the marker else -1
        if (board[i][j] == ' ')
        {
            spacesEmpty--;
            board[i][j] = p.getSide();
            return 0;
        }
        return -1;
    }
};

class Game
{
public:
    Game()
    {
    }

    void runGame()
    {
        int choice = 0;
        while (choice != EXIT_GAME)
        {
            showMenu();
            int choice = takeUserChoice();
            switch (choice)
            {
            case 1:
                playGame();
                break;
            }
            cout << endl
                 << endl;
            if (choice == EXIT_GAME)
                break;
            cout << "DEB: " << choice << endl;
        }
    }

    void playGame(bool oGoesFirst = 0)
    {
        Board b;
        Player p1('X'), p2('O');
        bool curTurn = oGoesFirst;

        int winner = 0;
        while (winner == 0)
        {
            b.displayBoard();

            cout << "Player " << curTurn << ": ";
            int row, col;
            cin >> row >> col;
            if (curTurn == 0)
                b.makeMove(row, col, p1);
            else
                b.makeMove(row, col, p2);
            winner = b.checkWinner();
            curTurn = !curTurn;
        }
        if (winner == 1)
            cout << "P1 Wins" << endl;
        else
            cout << "P2 Wins" << endl;
    }

    void showMenu()
    {
        cout << "\t\t\tTIC-TAC-TOE\n";
        cout << "\t1. Play\n";
        cout << "\t2. Quit\n";
    }

    int takeUserChoice()
    {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }
};

int main()
{
    Game g;
    g.runGame();
    return 0;
}