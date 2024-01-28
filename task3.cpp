#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void enter ()
{
    char c;

    cout << setw (68) << "                                                               ";
    c = _getch ();
    if (c == 13)
    {
        cout << endl;
        return;
    }
    cout << endl << setw (100) << "                Invalid key pressed, try again.               " << endl;
    return enter ();
}

void toss (char & player)
{
    srand (time (0));
    player = (rand () % 2 == 0) ? 'O' : 'X';
}

void initialize (char ** & board)
{
    board = new char * [3];
    for (int i = 0 ; i < 3 ; i++)
    {
        board [i] = new char [3];
        for (int j = 0 ; j < 3 ; j++)
        {
            board [i][j] = ' ';
        }
    }
}

void display (char ** & board)
{
    cout << endl << setw (75) << "  1   2   3  " << endl;
    cout << setw (75) << "-------------" << endl;
    for (int i = 0 ; i < 3 ; i++)
    {
        cout << setw (60) << i + 1 << "  |";
        for (int j = 0 ; j < 3 ; j++)
        {
            (board [i][j] == ' ') ? cout << "   " : (board [i][j] == 'O') ? cout << " O " : cout << " X ";
            cout << "|";
        }

        cout << endl << setw (75) << "-------------" << endl;
    }
}

void valid (char ** board, int & row, int & col)
{
    cout << setw (77) << "                      Enter row number: ";
    cin >> row;
    cout << setw (77) << "                      Enter col number: ";
    cin >> col;

    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board [row - 1][col - 1] == ' ')
        return;
    cout << endl << setw (81) << "Invalid Move, Try Again." << endl;
    return valid (board, row, col);
}

bool status (char ** board, char player, int i)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        if (board [0][i] == player && board [1][i] == player && board [2][i] == player)
        {
            cout << endl << setw (72) << "Status: Player " << player << " wins!" << endl;
            return true;
        }
        if (board [i][0] == player && board [i][1] == player && board [i][2] == player)
        {
            cout << endl << setw (72) << "Status: Player " << player << " wins!" << endl;
            return true;
        }
    }

    if (board [0][0] == player && board [1][1] == player && board [2][2] == player)
    {
        cout << endl << setw (72) << "Status: Player " << player << " wins!" << endl;
        return true;
    }
    if (board [0][2] == player && board [1][1] == player && board [2][0] == player)
    {
        cout << endl << setw (72) << "Status: Player " << player << " wins!" << endl;
        return true;
    }
    if (i == 9)
    {
        cout << endl << setw (78) << "Status: It's a draw!" << endl;
        return false;
    }

    cout << endl << setw (79) << "Status: Game Ongoing!" << endl;
    return false;
}

void shift (char & player)
{
    (player == 'O') ? player = 'X' : player = 'O';
}

void TicTacToe_game ()
{
    char ** board;
    char player;

    system ("cls");
    cout << setw (100) << "==============================================================" << endl;
    cout << setw (100) << "                Welcome to my TIK TAK TOE Game                " << endl;
    cout << setw (100) << "                Player 1 = X      Player 2 = O                " << endl;
    cout << setw (100) << "==============================================================" << endl;
    cout << setw (100) << "                                                              " << endl;
    cout << setw (100) << "             Press Enter to proceed for the toss.             " << endl;

    enter ();
    toss (player);

    cout << "                                                        ";
    (player == 'O') ? cout << "Player 2 (O) won the toss." << endl : cout << "Player 1 (X) won the toss." << endl;
    
    initialize (board);
    display (board);

    cout << setw (100) << "--------------------------------------------------------------" << endl << endl;

    int i = 0;

    while (i < 9)
    {
        cout << "                                                           ";
        (player == 'O') ? cout << "Player 2's turn (O)" << endl : cout << "Player 1's turn (X)" << endl;

        int row = 0, col = 0;

        valid (board, row, col);
        board [row - 1][col - 1] = player;
        display (board);

        i++;
        if (status (board, player, i))
        {
            cout << setw (100) << "==============================================================" << endl << endl;
            break;
        }

        if (i == 9)
            cout << setw (100) << "==============================================================" << endl << endl;
        else
            cout << setw (100) << "--------------------------------------------------------------" << endl << endl;
        shift (player);
    }
}

int main ()
{
    TicTacToe_game ();

    return 0;
}