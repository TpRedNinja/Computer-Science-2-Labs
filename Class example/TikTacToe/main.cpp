#include <iostream>
using namespace std;

// prototype
void display(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != '-')
        {
            cout << board[i][0] << " Wins!" << endl;
            return true;
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != '-')
        {
            cout << board[0][i] << " Wins!" << endl;
            return true;
        }
    }

    if (board[1][1] != '-')
    {
        // check the columns
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            cout << board[1][1] << " Wins!" << endl;
            return true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            cout << board[1][1] << " Wins!" << endl;
            return true;
        }
    }
    return false;
}

bool check_for_errors(int r, int c, char board[][3])
{
    if (r < 0 || r >= 3 || c < 0 || c >= 3)
    {
        return true;
    }
    if (board[r][c] != '-')
    {
        return true;
    }
    return false;
}

int main()
{
    char board[3][3] = {{'-', '-', '-'},
                        {'-', '-', '-'},
                        {'-', '-', '-'}};
    char turn = 'O';
    int row, col;
    do
    {
        cout << "Player " << turn << " enter the row and col: ";
        cin >> row >> col; // get row and col

        while (check_for_errors(row,col,board))
        {
            cout << "(Error!) Player " << turn << " enter the row and col: ";
            cin >> row >> col; // get row and col
        }
        board[row][col] = turn; // set to turn
        display(board);
        turn = (turn == 'O') ? 'X' : 'O';
    } while (!check(board));


    return 0;
}